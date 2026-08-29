class MyStack {
     Queue<Integer> q1;
     Queue<Integer> q2;
    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
    }
    
    public void push(int x) {
        q1.offer(x);
    }
    
    public int pop() {
         int last = 0;

         while(!q1.isEmpty()){
            int a = q1.peek();
            q1.poll();
            if(!q1.isEmpty()) q2.offer(a);
            else last = a;
         }     

         while(!q2.isEmpty()){
            int a = q2.peek();
            q1.offer(a);
            q2.poll();
         }
         return last;
    }
    
    public int top() {
        int first = 0;
         while(!q1.isEmpty()){
            int a = q1.peek();
            q1.poll();
            if(q1.isEmpty()) first = a;
            q2.offer(a);
         }     
         while(!q2.isEmpty()){
            int a = q2.peek();
            q1.offer(a);
            q2.poll();
         }
         return first;
    }
    
    public boolean empty() {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */