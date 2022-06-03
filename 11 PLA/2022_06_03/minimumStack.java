import java.util.Stack;

public class minimumStack {

    static class stack {
        class pair {
            int val;
            int min;

            pair() {

            }

            pair(int val, int min) {
                this.val = val;
                this.min = min;
            }
        }

        Stack<pair> st = new Stack<>();

        public void push(int val) {
            pair top = new pair();
            if (st.isEmpty()) {
                st.push(new pair(val, val));
                return;
            }
            top = st.peek();
            if (top.min > val) {
                st.push(new pair(val, val));
            } else {
                st.push(new pair(val, top.min));
            }
        }

        public int pop() {
            pair top = st.peek();
            st.pop();
            return top.val;
        }

        public int getMin() {
            pair top = st.peek();
            return top.min;
        }

        public int peek() {
            pair top = st.peek();
            return top.val;
        }
    }

    public static void main(String[] args) {
        stack st = new stack();
        st.push(10);
        st.push(20);
        st.push(5);
        st.push(7);
        st.push(30);
        st.push(1);
        System.out.println(st.getMin());
        st.pop();
        st.pop();
        st.pop();
        st.pop();
        System.out.println(st.getMin());
    }
}
