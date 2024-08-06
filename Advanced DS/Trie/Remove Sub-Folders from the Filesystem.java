// Problem: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/

// Reference: https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/solutions/408955/java-trie-solution-clean-code/
//            https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/solutions/408955/java-trie-solution-clean-code/comments/1775809

/**************************************************************************************************************************************************************************/


class Solution {
    private class TrieNode {
        Map<String, TrieNode> children;
        int wordIndex;

        TrieNode() {
            this.children = new HashMap<>();
            wordIndex = -1;
        }
    }

    private void insertInTrie(String str, int strIdx, TrieNode root) {
        String[] parts = str.substring(1).split("/");

        for (String part: parts) {
            if (!root.children.containsKey(part)) {
                root.children.put(part, new TrieNode());
            }

            root = root.children.get(part);
        }

        root.wordIndex = strIdx;
    }

    private void fetchParentFolders(TrieNode root, List<String> parentFolders, String[] folder) {
        for (Map.Entry<String, TrieNode> entry: root.children.entrySet()) {
            if (entry.getValue().wordIndex != -1) {
                parentFolders.add(folder[entry.getValue().wordIndex]);
            } else {
                fetchParentFolders(entry.getValue(), parentFolders, folder);
            }
        }
    }

    public List<String> removeSubfolders(String[] folder) {
        TrieNode root = new TrieNode();

        for (int i = 0; i < folder.length; i++) {
            TrieNode node = root;
            insertInTrie(folder[i], i, node);
        }

        List<String> parentFolders = new ArrayList<>();

        fetchParentFolders(root, parentFolders, folder);

        return parentFolders;
    }
}