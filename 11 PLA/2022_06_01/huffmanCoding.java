import java.util.ArrayList;
import java.util.PriorityQueue;

/*
To solve huffman coding
    1 Ascii Value
    2 Define your own binary value and map them with the real binary val of character
    3 Use binary min heap
O(Nlog(N))
*/
public class huffmanCoding {
    static class pair {
        int first;
        int second;

        pair(int start, int end) {
            this.first = start;
            this.second = end;
        }
    }

    public static void main(String[] args) {
        int s[] = { 1, 3, 0, 5, 8, 5 };
        int e[] = { 2, 4, 6, 7, 9, 9 };

        selectAct(s, e);
    }

    public static void selectAct(int[] start, int[] end) {
        ArrayList<pair> arr = new ArrayList<>();
        PriorityQueue<pair> pq = new PriorityQueue<>((p1, p2) -> p1.first - p2.first);
        for (int i = 0; i < start.length; i++) {
            pq.add(new pair(start[i], end[i]));
        }
        pair it = pq.poll();
        int s = it.second;
        int e = it.first;
        arr.add(new pair(s, e));
        while (!pq.isEmpty()) {
            pair itr = pq.poll();
            if (itr.second >= e) {
                s = itr.second;
                e = itr.first;
                arr.add(new pair(s, e));
            }
        }
        for (pair p : arr) {
            System.out.println(p.first + " "+ p.second);
        }
    }
}
