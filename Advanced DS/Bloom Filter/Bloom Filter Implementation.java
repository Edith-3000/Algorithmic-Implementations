import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BloomFilter {
    private final int m; // size of bloom filter
    private final int k; // number of hash functions
    private int n; // total count of the elements inserted
    private final int[] bloomFilter;

    public BloomFilter(int m, int k) {
        this.m = m;
        this.k = k;
        this.n = 0;
        this.bloomFilter = new int[m];
        Arrays.fill(this.bloomFilter, 0);
    }

    private int md5Hash(String key) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] digest = md.digest(key.getBytes());

            int hash = 0;

            for (int i = 0; i < 32; i++) {
                int byteIndex = i / 8;
                int bitIndexInByte = i % 8;

                int bit = (digest[byteIndex] >> bitIndexInByte) & 1;

                hash |= (bit << i);
            }

            // Ensure the resulting hash is positive by masking the sign bit
            return hash & 0x7FFFFFFF;  // Mask the sign bit
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
    }

    private List<Integer> getBitArrayIndices(String key) {
        List<Integer> indexList = new ArrayList<>();
        int hashCodeOfKey = key.hashCode();

        for (int i = 1; i <= k; i++) {
            int md5HashCodeOfKey = md5Hash(key);

            // Ensure the modulus result is always non-negative
            int index = (hashCodeOfKey + (i * md5HashCodeOfKey)) % m;
            if (index < 0) {
                index += m;  // If index is negative, adjust to a positive value
            }

            indexList.add(index);
        }

        return indexList;
    }

    public void insert(String key) {
        for (int idx: getBitArrayIndices(key)) {
            bloomFilter[idx] = 1;
        }

        n += 1;
    }

    public boolean contains(String key) {
        for (int idx: getBitArrayIndices(key)) {
            if (bloomFilter[idx] == 0) {
                return false;
            }
        }

        return true;
    }

    public void generateStats() {
        double m = this.m;
        double k = this.k;
        double n = this.n;

        double false_positive_probability = Math.pow((1.0 - Math.exp(-(k * n) / m)), k);

        // ANSI escape codes for colors
        String BLUE = "\033[34m";
        String GREEN = "\033[32m";
        String RESET = "\033[0m";  // Resets color back to default

        System.out.println(BLUE + "Number of bits in bloom filter: " + this.m + RESET);
        System.out.println(BLUE + "Number of hash functions in use: " + this.k + RESET);
        System.out.println(BLUE + "Number of keys inserted so far: " + this.n + RESET);

        System.out.println(GREEN + "Predicted probability of false positives: " +
                String.format("%.30f", false_positive_probability) + RESET);

        System.out.println(GREEN + "Predicted false positive rate: " +
                String.format("%.30f", (false_positive_probability * 100.0)) + "%" + RESET);

        System.out.println();
    }

    public void reset() {
        n = 0;
        Arrays.fill(bloomFilter, 0);
    }

    public static void main(String[] args) {
        BloomFilter bloomFilter = new BloomFilter(4000, 3);

        bloomFilter.insert("apple");
        System.out.println("Contains apple: " + bloomFilter.contains("apple"));
        bloomFilter.generateStats();

        bloomFilter.insert("guava");
        System.out.println("Contains guava: " + bloomFilter.contains("guava"));
        bloomFilter.generateStats();

        System.out.println("Contains grapes: " + bloomFilter.contains("grapes"));
        bloomFilter.generateStats();

        bloomFilter.insert("custard apple");
        System.out.println("Contains custard apple: " + bloomFilter.contains("custard apple"));
        bloomFilter.generateStats();

        System.out.println("Contains kiwi: " + bloomFilter.contains("custard kiwi"));
        bloomFilter.generateStats();

        bloomFilter.reset();
        bloomFilter.generateStats();
    }
}
