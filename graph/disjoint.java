import java.util.*;

public class disjoint
{

	private HashMap<Long, Node> map = new HashMap<>();

	class Node
	{
		int rank;
		long data;
		Node parent;
	}


	// Create a set with one element
	public void makeSet(long data)
	{
		Node node = new Node();
		node.data = data;
		node.rank = 0;
		node.parent = node;

		map.put(data, node);
	}

	// Combines two set together into one
	// Does union by rank

	public boolean union(long data1, long data2)
	{
		Node node1 = map.get(data1);
		Node node2 = map.get(data2);

		Node parent1 = findSet(node1);
		Node parent2 = findSet(node2);

		// If they are part of the same set, do nothing
		if(parent1 == parent2)
		{
			return false;
		}

		// whosoever's rank is higher becomes the parent of the other
		if(parent1.rank > parent2.rank)
		{
			parent2.parent = parent1;
		}
		else if(parent1.rank < parent2.rank)
		{
			parent1.parent = parent2;
		}
		else
		{
			parent1.rank += 1;
			parent2.parent = parent1;
		}

		return true;
	}

	// Find the representative of the set
	// If the set contains only one el, then node.parent = parent
	// else recurse till the above condition is reached
	private Node findSet(Node node)
	{
		// Node node = map.get(data);
		Node parent = node.parent;

		if(parent == node)
			return parent;
		else
		{
			return findSet(node.parent);
		}
	}

	public long findSet(long data)
	{
		return findSet(map.get(data)).data;
	}
	

	public static void main(String args[]) {
        disjoint ds = new disjoint();
        ds.makeSet(1);
        ds.makeSet(2);
        ds.makeSet(3);
        ds.makeSet(4);
        ds.makeSet(5);
        ds.makeSet(6);
        ds.makeSet(7);

        ds.union(1, 2);
        ds.union(2, 3);
        ds.union(4, 5);
        ds.union(6, 7);
        ds.union(5, 6);
        ds.union(3, 7);

        System.out.println(ds.findSet(1));
        System.out.println(ds.findSet(2));
        System.out.println(ds.findSet(3));
        System.out.println(ds.findSet(4));
        System.out.println(ds.findSet(5));
        System.out.println(ds.findSet(6));
        System.out.println(ds.findSet(7));

        if(ds.findSet(1) == ds.findSet(4))
	        System.out.println("YES");
		else
			System.out.println("NO");
	}

}