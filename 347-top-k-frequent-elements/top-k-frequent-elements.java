class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> freq = new HashMap<>();

        for(int num  : nums){
            freq.put(num, freq.getOrDefault(num,0) + 1);
        }
         
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[1] - b[1]);
        
        for(int key : freq.keySet()){
            pq.add(new int[]{key,freq.get(key)});
            if(pq.size() > k){
                pq.poll();
            }
        }

        int[] result = new int[k];
        int i = 0;

        while(!pq.isEmpty()){
            result[i++] = pq.poll()[0];
        } 

        return result;
    }
}