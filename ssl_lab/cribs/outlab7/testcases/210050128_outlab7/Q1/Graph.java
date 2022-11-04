package Q1;

import java.util.Map.Entry;
import java.security.spec.DSAGenParameterSpec;
import java.util.*; 
import java.util.regex.*;

public class Graph {

    // Assume maximum path length to be less than INF
    private static Integer INF = 1000*1000*1000 ;
    private Map<String, Node> nodeMap = new HashMap<>() ;
    
    public static class pair{
        public String node_name;
        public Integer len;
        private pair(String node_name,Integer len){
            this.node_name = node_name;
            this.len = len;
        }
    }

    public void addNode(String name) {
        /*
         * TODO: Implement this method
         */
        Node newNode = new Node(name); 
        nodeMap.put(name,newNode);
    }

    public void addDirectedEdge(String nameA, String nameB, Integer distance) {
        /*
         * TODO: Implement this method
         * Check if nodes with nameA and nameB exist.
         */
        nodeMap.get(nameA).adjacentNodes.put(nodeMap.get(nameB),distance);
    }

    private void relaxations(Node node, PriorityQueue<pair> d_set,Map<String,Integer> map){
        for (Map.Entry<Node,Integer> neighbour : node.adjacentNodes.entrySet()) {
            Integer len = neighbour.getValue();
            Integer dist_till_now = map.get(node.getName());
            Integer curr_n_dist = map.get(neighbour.getKey().getName());

            // System.out.print(len + " " + dist_till_now + " " + curr_n_dist +  "\n");
            if (len + dist_till_now < curr_n_dist) {
                // System.out.println(d_set.contains(new pair(neighbour.getKey().getName(),curr_n_dist)) + " -ldj");;
               d_set.remove(new pair(neighbour.getKey().getName(),curr_n_dist)); 
               d_set.add(new pair(neighbour.getKey().getName(),len + dist_till_now));
               map.replace(neighbour.getKey().getName(), curr_n_dist, len + dist_till_now);
            }
        }
    }

    public Map<String, Integer> dijkstraAlgorithm(String source) {
        /*
         * TODO: Implement this method
         * Return a map of name of all the nodes
         * with the minimum distance from source node
         */
        Map<String, Integer> map = new HashMap<>();
        

        PriorityQueue<pair> d_set = new PriorityQueue<pair>(new Comparator<pair>() {
           @Override 
           public int compare(pair p1, pair p2){
                if (p1.len == p2.len) {
                   return 1; 
                }
                return p1.len - p2.len;
           }
        });

        // SortedSet<pair> d_set = new TreeSet<pair>(new Comparator<pair>() {
        //    @Override 
        //    public int compare(pair p1, pair p2){
        //         if (p1.len == p2.len) {
        //            return 1; 
        //         }
        //         return p1.len - p2.len;
        //    }
        // });

        d_set.add(new pair(source,0));

        for (Map.Entry<String,Node> elem : nodeMap.entrySet()) {
           if (elem.getKey() != source) {
              d_set.add(new pair(elem.getKey(),INF));
              map.put(elem.getKey(),INF);
           } 
        }

        map.put(source, 0);
        while(!d_set.isEmpty()){
            // System.out.println(d_set.size() + " this is the size");
            // Node currNode = d_set.first().node;  
            // relaxations(currNode, d_set, map);
            // d_set.remove(d_set.first());
            pair currNode_pair = d_set.peek();  
            // System.out.println(d_set.first().len); 
            // System.out.println(d_set.first().node_name); 
            relaxations(nodeMap.get(currNode_pair.node_name), d_set, map);
            d_set.remove();
            // d_set.remove(new pair(currNode_pair.node_name,currNode_pair.len));
            // Iterator<pair> it = d_set.iterator();
            // d_set.remove(it.next());
            // it.remove();
            // d_set.remove(Iterables.get(d_set, 0));
            // System.out.println(d_set.contains(it.next()));
        }
            
        // Iterator<pair> it = d_set.iterator();
        // while(it.hasNext()){
        //     System.out.println(it.next().len);
        // }            
        // System.out.println(d_set.first().len); 
        

            // System.out.println(d_set.first().len); 
            // System.out.println(d_set.first().node_name); 
            // System.out.println(map.get(source));

        // for (int i = 0; i < 1; i++) {
        //     System.out.println(d_set.size());
        //     pair currNode_pair = d_set.first();  
        //     System.out.println(d_set.first().len); 
        //     System.out.println(d_set.first().node_name); 
        //     relaxations(nodeMap.get(currNode_pair.node_name), d_set, map);
        //     d_set.remove(d_set.first());
        // }
        return map;
    } 
}