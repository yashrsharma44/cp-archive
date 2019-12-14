import java.util.*;

public class Disjoint
{
	HashMap<Long, Node> map = new HashMap<>();

	public class Node
	{
		long data;
		int rank;
		Node parent;
	}

	public void makeSet(long data)
	{
		Node node = new Node();
		node.data = data;
		node.rank = 0;
		node.parent = node;

		map.put(data, node);
	}

	public long findSet(long data)
	{
		return findSet(map.get(data)).data;
	}

	private Node findSet(Node node)
	{
		Node parent = node.parent;
		if(parent == node)
			return node;

		return findSet(parent);
	}

	public boolean union(long data1, long data2)
	{
		Node node1 = map.get(data1);
		Node node2 = map.get(data2);

		Node parent1 = findSet(node1);
		Node parent2 = findSet(node2);

		if(parent1 == parent2)
			return false;

		if(parent1.rank > parent2.rank)
			parent2.parent = parent1;

		else if(parent2.rank > parent1.rank)
			parent1.parent = parent2;
		else
		{
			parent2.parent = parent1;
			parent1.rank +=1;
		}
		return true;
	}


	public static void main(String args[])
	{
		int V = 3;
		int edgeList[][] = {{0,1},{1,3},{2,0},{2,3},{1,4}};
		// edgeList[0] = {0,1};
		// edgeList[1] = {1,2};
		// edgeList[2] = {2,0};

		Disjoint ds = new Disjoint();
		ds.makeSet(0);
		ds.makeSet(1);
		ds.makeSet(2);
		ds.makeSet(3);
		ds.makeSet(4);

		boolean isCycle = false;

		for(int i=0;i<edgeList.length;i++)
		{
			int x = (int)ds.findSet(edgeList[i][0]);
			int y = (int)ds.findSet(edgeList[i][1]);

			if(x==y)
			{
				isCycle = true;
				break;
			}

			ds.union(x,y);
		}

		if (isCycle)
		{
			System.out.println("Is Cycle!");
		}
		else
		{
			System.out.println("Not a cycle");
		}
	}
}


class Graph
{
	
}