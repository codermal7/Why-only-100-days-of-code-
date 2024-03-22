public class Solution {
    public int ladderLength(String start, String end, HashSet<String> dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (dict.size <= 0) {
            return 0;
        }
        
        HashMap<String, ArrayList<String>> nodeMap = new HashMap<String, ArrayList<String>>();
        ArrayList<String> endPoint = new ArrayList<String>();
        
        for (String s : dict) {
            if (isAdj(s, end)) {
                endPoint.add(s);
            }
        }
        
        if (endPoint.size() == 0) {
            return 0;
        }
        
        ArrayList<String> startPoint = new ArrayList<String>();
        for (String s : dict) {
            if (isAdj(start, s)) {
                startPoint.add(s);
            }
        }
        if (startPoint.size() == 0) {
            return 0;
        }
        
        for (String s : dict) {
            ArrayList<String> neighbor = new ArrayList<String>();
            for (String s1 : dict) {
                if (isAdj(s, s1)) {
                    neighbor.add(s1);
                }
            }
            nodeMap.put(s, neighbor);
        }

        int minHop = Integer.MAX_VALUE;
        for (String s : startPoint) {
            Queue<String> queue = new LinkedList<String>();
            queue.add(s);
            int hop = 0;
            boolean exist = false;
            HashSet<String> visited = new HashSet<String>();
            int[] level = new int[dict.size()];
            for (int i = 0; i < level.length; i++) {
                level[i] = 0;
            }
            level[0]++;
            int levelNum = 0;
            visited.add(s);
            while (queue.peek() != null) {
                String node = queue.remove();
                if (endPoint.contains(node)) {
                    exist = true;
                    break;
                } else {
                    for (String neighbor : nodeMap.get(node)) {
                        if (!visited.contains(neighbor)) {
                            level[levelNum + 1]++;
                            queue.add(neighbor);
                            visited.add(neighor);
                        }
                    }
                    level[levelNum]--;
                    if (level[levelNum] == 0) {
                        levelNum++;
                        hop++;
                    }
                }
            }
            if (exist && hop < minHop) {
                minHop = hop;
            }
            }
            if (minHop == Integer.MAX_VALUE) {
                return 0;
            }
            return minHop + 2;
        }
    
    public boolean isAdj(String s1, String s2) {
        int diffCount = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diffCount++;
                if (diffCount > 1) {
                    return false;
                }
            }
        }
        if (diffCount != 1) {
            return false;
        }
        return true;
    }
}