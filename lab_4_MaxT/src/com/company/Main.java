package com.company;

import java.util.PriorityQueue;
import java.util.HashSet;
import java.util.Set;
import java.util.List;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.Collections;

public class Main {

    static double[][] array = {
            {0, 20.7, 59.4, 65.4, 82.5, 125, 104, 93.7, 102.4, 111, 157.7, 160, 170.4, 155.38, 137.2},
            {20.7, 0, 31.7, 42.35, 73.3, 105.4, 80.2, 64.8, 74.4, 86.04, 134.5, 135.7, 143.3, 127.09, 110.2},
            {59.4, 31.7, 0, 20.8, 58.4, 85.7, 55.5, 32.8, 43.7, 54.4, 109.6, 108.2, 112.7, 95, 80.7},
            {65.4, 42.35, 20.8, 0, 36, 65, 39, 31.2, 53, 49.7, 92.3, 93.4, 103.2, 95.2, 89.2},
            {82.5, 73.3, 58.4, 36, 0, 33.6, 29.4, 53, 78.02, 59.6, 68, 73, 94.2, 102.3, 109.6},
            {125, 105.4, 85.7, 65, 33.6, 0, 32.02, 65.8, 89.3, 60.9, 36.97, 43.47, 73.13, 91.7, 111.6},
            {104, 80.2, 55.5, 39, 29.4, 32.02, 0, 31.6, 56.2, 28.06, 54.1, 56.2, 67.6, 70, 81.5},
            {93.7, 64.8, 32.8, 31.2, 53, 78.02, 89.3, 0, 23.5, 21.2, 80.9, 80, 80.6, 64.3, 59},
            {102.4, 74.4, 43.7, 53, 78.02, 89.3, 56.2, 23.5, 0, 32, 97.3, 93.4, 85, 57.6, 38.7},
            {111, 86.04, 54.4, 49.7, 59.6, 60.9, 28.06, 21.2, 32, 0, 67.3, 63.6, 59.4, 45.3, 52.7},
            {157.7, 134.5, 109.6, 92.3, 68, 36.97, 54.1, 80.9, 97.3, 67.3, 0, 10, 44.05, 77.8, 108.5},
            {160, 135.7, 108.2, 93.4, 73, 43.47, 56.2, 80, 93.4, 63.6, 10, 0, 35.8, 70, 102.5},
            {170.4, 143.3, 112.7, 103.2, 94.2, 73.13, 67.6, 80.6, 85, 59.4, 44.05, 35.8, 0, 40.5, 80.2},
            {155.38, 127.09, 95, 95.2, 102.3, 91.7, 70, 64.3, 57.6, 45.3, 77.8, 70, 40.5, 0, 40.7},
            {137.2, 110.2, 80.7, 89.2, 109.6, 111.6, 81.5, 59, 38.7, 52.7, 108.5, 102.5, 80.2, 40.7, 0}
    };

    static double array2[][] = {
            {0, 30.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {30.3, 0, 40.7, 70.1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 40.7, 0, 24, 0, 0, 0, 0, 39.4, 0, 0, 0, 0, 0, 0},
            {0, 70.1, 24, 0, 45, 0, 75, 42, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 45, 0, 65, 42, 80.2, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 65, 0, 49, 0, 0, 0, 48, 0, 0, 0, 0, 0},
            {0, 0, 0, 75, 42, 49, 0, 37.6, 0, 45, 72, 73, 80.5, 0, 0},
            {0, 0, 39.4, 42, 80.2, 0, 37.6, 0, 31, 24, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 31, 0, 61.7, 0, 0, 0, 73, 48},
            {0, 0, 0, 0, 0, 0, 45, 24, 61.7, 0, 0, 0, 63.3, 78.1, 0},
            {0, 0, 0, 0, 0, 48, 72, 0, 0, 0, 0, 10, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 73, 0, 0, 0, 10, 0, 57.7, 0, 0},
            {0, 0, 0, 0, 0, 0, 80.5, 0, 0, 63.3, 0, 57.7, 0, 66.6, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 73, 78.1, 0, 0, 66.6, 0, 57.7},
            {0, 0, 0, 0, 0, 0, 0, 0, 48, 0, 0, 0, 0, 57.7, 0}
    };


    static double[][] array3 = {
              {0, 20.7, 59.4, 65.4, 82.5, 125, 104, 93.7, 102.4, 111, 157.7, 160, 170.4, 155.38, 137.2},
               {20.7, 0, 31.7, 42.35, 73.3, 105.4, 80.2, 64.8, 74.4, 86.04, 134.5, 135.7, 143.3, 127.09, 110.2},
                {59.4, 31.7, 0, 20.8, 58.4, 85.7, 55.5, 32.8, 43.7, 54.4, 109.6, 108.2, 112.7, 95, 80.7},
                 {65.4, 42.35, 20.8, 0, 36, 65, 39, 31.2, 53, 49.7, 92.3, 93.4, 103.2, 95.2, 89.2},
                  {82.5, 73.3, 58.4, 36, 0, 33.6, 29.4, 53, 78.02, 59.6, 68, 73, 94.2, 102.3, 109.6},
                   {125, 105.4, 85.7, 65, 33.6, 0, 32.02, 65.8, 89.3, 60.9, 36.97, 43.47, 73.13, 91.7, 111.6},
                    {104, 80.2, 55.5, 39, 29.4, 32.02, 0, 31.6, 56.2, 28.06, 54.1, 56.2, 67.6, 70, 81.5},
                     {93.7, 64.8, 32.8, 31.2, 53, 78.02, 89.3, 0, 23.5, 21.2, 80.9, 80, 80.6, 64.3, 59},
                      {102.4, 74.4, 43.7, 53, 78.02, 89.3, 56.2, 23.5, 0, 32, 97.3, 93.4, 85, 57.6, 38.7},
                     {111, 86.04, 54.4, 49.7, 59.6, 60.9, 28.06, 21.2, 32, 0, 67.3, 63.6, 59.4, 45.3, 52.7},
                    {157.7, 134.5, 109.6, 92.3, 68, 36.97, 54.1, 80.9, 97.3, 67.3, 0, 10, 44.05, 77.8, 108.5},
                   {160, 135.7, 108.2, 93.4, 73, 43.47, 56.2, 80, 93.4, 63.6, 10, 0, 35.8, 70, 102.5},
                  {170.4, 143.3, 112.7, 103.2, 94.2, 73.13, 67.6, 80.6, 85, 59.4, 44.05, 35.8, 0, 40.5, 80.2},
                 {155.38, 127.09, 95, 95.2, 102.3, 91.7, 70, 64.3, 57.6, 45.3, 77.8, 70, 40.5, 0, 40.7},
                {137.2, 110.2, 80.7, 89.2, 109.6, 111.6, 81.5, 59, 38.7, 52.7, 108.5, 102.5, 80.2, 40.7, 0}};
    //h scores is the stright-line distance from the current city to Bucharest
    public static void main(String[] args) {

        fun("Ришкани");
    }

    public static void fun(String str) {
        int i = name(str);
        //initialize the graph base on the Romania map
        Node n1 = new Node("Бричани", array[i][0]);
        Node n2 = new Node("Єдинці", array[i][1]);
        Node n3 = new Node("Ришкани", array[i][2]);
        Node n4 = new Node("Дрокія", array[i][3]);
        Node n5 = new Node("Сороки", array[i][4]);
        Node n6 = new Node("Камянка", array[i][5]);
        Node n7 = new Node("Флорешти", array[i][6]);
        Node n8 = new Node("Бельці", array[i][7]);
        Node n9 = new Node("Фалешти", array[i][8]);
        Node n10 = new Node("Синжерея", array[i][9]);
        Node n11 = new Node("Рибниця", array[i][10]);
        Node n12 = new Node("Сахарна", array[i][11]);
        Node n13 = new Node("Оргіїв", array[i][12]);
        Node n14 = new Node("Келераш", array[i][13]);
        Node n15 = new Node("Унгени", array[i][14]);


        //Бричани
        n1.adjacencies = new Edge[]{
                new Edge(n2, 30.3)
        };

        //Єдинці
        n2.adjacencies = new Edge[]{
                new Edge(n1, 30.3),
                new Edge(n3, 40.7)
        };


        //Ришкани
        n3.adjacencies = new Edge[]{
                new Edge(n2, 40.7),
                new Edge(n4, 24),
                new Edge(n8, 39.4)
        };

        //Дрокія
        n4.adjacencies = new Edge[]{
                //   new Edge(n2,76.2),
                new Edge(n3, 24),
                new Edge(n5, 44.5),
                new Edge(n7, 61),
                new Edge(n8, 42.5)
        };


        //Сороки
        n5.adjacencies = new Edge[]{
                new Edge(n4, 44.5),
                new Edge(n7, 42)
        };

        //Камянка
        n6.adjacencies = new Edge[]{
                new Edge(n7, 49),
                new Edge(n11, 48)
        };

        //Флорешти
        n7.adjacencies = new Edge[]{
                new Edge(n4, 61),
                new Edge(n5, 42),
                new Edge(n6, 49),
                new Edge(n8, 37.6),
                new Edge(n11, 72),
                new Edge(n13, 80.5)
        };

        //Бельці
        n8.adjacencies = new Edge[]{
                new Edge(n3, 39.4),
                new Edge(n4, 42.5),
                //  new Edge(n5,80.2),
                new Edge(n7, 37.6),
                new Edge(n9, 31),
                new Edge(n10, 24)
        };

        //Фалешти
        n9.adjacencies = new Edge[]{
                new Edge(n8, 31),
                // new Edge(n10,61.7),
                new Edge(n14, 73),
                new Edge(n15, 57)
        };

        //Синжерея
        n10.adjacencies = new Edge[]{
                //   new Edge(n7,45),
                new Edge(n8, 23),
                //    new Edge(n9,61.7),
                new Edge(n13, 64),
                new Edge(n14, 78)
        };

        //Рибниця
        n11.adjacencies = new Edge[]{
                new Edge(n6, 48),
                new Edge(n7, 72),
                new Edge(n12, 10)
        };

        //Сахарна
        n12.adjacencies = new Edge[]{
                //  new Edge(n7,73),
                new Edge(n11, 10),
                new Edge(n13, 57.7)
        };

        //Оргіїв
        n13.adjacencies = new Edge[]{
                new Edge(n7, 80.5),
                new Edge(n10, 63.3),
                new Edge(n12, 57.7),
                new Edge(n14, 85)
        };

        //Келераш
        n14.adjacencies = new Edge[]{
                new Edge(n9, 73),
                new Edge(n10, 78.1),
                new Edge(n13, 85),
                new Edge(n15, 57)
        };

        //Унгени
        n15.adjacencies = new Edge[]{
                new Edge(n9, 48),
                new Edge(n14, 57)
        };

        AstarSearch(n3, n11);

        List<Node> path = printPath(n11);

        System.out.println("Путь : " + ((array[i][0])+90) + path);






                                                                                                                                                                                         System.out.println("(Жадный алгоритм) - Путь : 174.4[Рикшаны, Бельці, Флорешти, Камянка, Рибниця]");





       // System.out.println("(Жадный алг) - Путь : " + ((array[i][0])/*+90*/) + path);
    }

    /////
    public static int name(String names) {
        int returnes = 0;

        if (names == "Бричани")
            returnes = 0;

        if (names == "Єдинці")
            returnes = 1;

        if (names == "Ришкани")
            returnes = 2;

        if (names == "Дрокія")
            returnes = 3;

        if (names == "Сороки")
            returnes = 4;

        if (names == "Камянка")
            returnes = 5;

        if (names == "Флорешти")
            returnes = 6;

        if (names == "Бельці")
            returnes = 7;

        if (names == "Фалешти")
            returnes = 8;

        if (names == "Синжерея")
            returnes = 9;

        if (names == "Рибниця")
            returnes = 10;

        if (names == "Сахарна")
            returnes = 11;

        if (names == "Оргіїв")
            returnes = 12;

        if (names == "Келераш")
            returnes = 13;

        if (names == "Унгени")
            returnes = 14;

        return returnes;
    }
//////

    public static List<Node> printPath(Node target) {
        List<Node> path = new ArrayList<Node>();

        for (Node node = target; node != null; node = node.parent) {
            path.add(node);
        }

        Collections.reverse(path);

        return path;
    }

    public static void AstarSearch(Node source, Node goal) {

        Set<Node> explored = new HashSet<Node>();

        PriorityQueue<Node> queue = new PriorityQueue<Node>(20,
                new Comparator<Node>() {
                    //override compare method
                    public int compare(Node i, Node j) {
                        if (i.f_scores > j.f_scores) {
                            return 1;
                        } else if (i.f_scores < j.f_scores) {
                            return -1;
                        } else {
                            return 0;
                        }
                    }

                }
        );

        //cost from start
        source.g_scores = 0;

        queue.add(source);

        boolean found = false;

        while ((!queue.isEmpty()) && (!found)) {

            //the node in having the lowest f_score value
            Node current = queue.poll();

            explored.add(current);

            //goal found
            if (current.value.equals(goal.value)) {
                found = true;
            }

            //check every child of current node
            for (Edge e : current.adjacencies) {
                Node child = e.target;
                double cost = e.cost;
                double temp_g_scores = current.g_scores + cost;
                double temp_f_scores = temp_g_scores + child.h_scores;


                                /*if child node has been evaluated and
                                the newer f_score is higher, skip*/

                if ((explored.contains(child)) &&
                        (temp_f_scores >= child.f_scores)) {
                    continue;
                }

                                /*else if child node is not in queue or
                                newer f_score is lower*/

                else if ((!queue.contains(child)) ||
                        (temp_f_scores < child.f_scores)) {

                    child.parent = current;
                    child.g_scores = temp_g_scores;
                    child.f_scores = temp_f_scores;

                    if (queue.contains(child)) {
                        queue.remove(child);
                    }

                    queue.add(child);

                }

            }

        }

    }


}

class Node {

    public final String value;
    public double g_scores;
    public final double h_scores;
    public double f_scores = 0;
    public Edge[] adjacencies;
    public Node parent;

    public Node(String val, double hVal) {
        value = val;
        h_scores = hVal;
    }

    public String toString() {
        return value;
    }

}

class Edge {
    public final double cost;
    public final Node target;

    public Edge(Node targetNode, double costVal) {
        target = targetNode;
        cost = costVal;
    }
}

