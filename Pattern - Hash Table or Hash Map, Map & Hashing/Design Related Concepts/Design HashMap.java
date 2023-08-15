// Reference: https://www.youtube.com/watch?v=sHpjxXX81Gw

/*****************************************************************************************************************************************************************/

import java.util.ArrayList;
import java.util.List;

class MyHashMap<K, V> {
    private int size; // number of elements in the bucket
    private int capacity; // length of the bucket
    private final int INITIAL_CAPACITY = 5; // initial length of the bucket
    private List<MyHashMapNode<K, V>> bucket;

    private class MyHashMapNode<A, B> {
        A key;
        B value;
        MyHashMapNode<A, B> next;

        MyHashMapNode(A key, B value) {
            this.key = key;
            this.value = value;
        }
    }

    public MyHashMap() {
        size = 0;
        capacity = INITIAL_CAPACITY;

        bucket = new ArrayList<>();

        for(int i = 0; i < capacity; i++) {
            bucket.add(null);
        }
    }

    private int getBucketIndex(K key) {
        int hashCode = key.hashCode();
        int bucketIndex = hashCode % capacity;
        return bucketIndex;
    }

    private void rehash() {
        System.out.println("Re-hashing buckets");

        size = 0;
        capacity *= 2;

        List<MyHashMapNode<K, V>> oldBucket = bucket;
        bucket = new ArrayList<>();

        for(int i = 0; i < capacity; i++) {
            bucket.add(null);
        }

        for(int i = 0; i < oldBucket.size(); i++) {
            MyHashMapNode<K, V> head = oldBucket.get(i);

            while(head != null) {
                put(head.key, head.value);
                head = head.next;
            }
        }
    }

    public void put(K key, V value) {
        int bucketIndex = getBucketIndex(key);

        MyHashMapNode<K, V> head = bucket.get(bucketIndex);

        while(head != null) {
            if(head.key.equals(key)) {
                System.out.println("Updated key: " + key);
                head.value = value;
                return;
            }

            head = head.next;
        }

        MyHashMapNode<K, V> newEntry = new MyHashMapNode<>(key, value);

        newEntry.next = bucket.get(bucketIndex);
        bucket.set(bucketIndex, newEntry);

        size += 1;

        double loadFactor = (1.0 * size) / capacity;

        System.out.println("Inserted key: " + key);
        System.out.println("Load Factor: " + loadFactor);

        if(loadFactor > 0.75) {
            rehash();
        }
    }

    public V get(K key) {
        int bucketIndex = getBucketIndex(key);

        MyHashMapNode<K, V> head = bucket.get(bucketIndex);

        while(head != null) {
            if(head.key.equals(key)) {
                return head.value;
            }

            head = head.next;
        }

        return null;
    }

    public void remove(K key) {
        int bucketIndex = getBucketIndex(key);

        MyHashMapNode<K, V> head = bucket.get(bucketIndex);
        MyHashMapNode<K, V> prev = null;

        while(head != null) {
            if(head.key.equals(key)) {
                if(prev == null) {
                    bucket.set(bucketIndex, head.next);
                }

                else {
                    prev.next = head.next;
                    head.next = null;
                }

                size -= 1;
                break;
            }

            else {
                prev = head;
                head = head.next;
            }
        }
    }

    public int size() {
        return size;
    }
}

public class Main {
    public static void main(String[] args) {
        MyHashMap<Integer, String> myHashMap = new MyHashMap<>();

        myHashMap.put(1, "a");
        myHashMap.put(6, "riddhi");
        myHashMap.put(5, "absxd");
        myHashMap.put(3, "abc");
        myHashMap.put(5, "riddd");

        System.out.println(myHashMap.get(5));
        System.out.println(myHashMap.get(1));
        System.out.println(myHashMap.get(6));
        System.out.println(myHashMap.get(3));
        System.out.println(myHashMap.get(7));
    }
}
