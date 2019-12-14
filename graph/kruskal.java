import java.util.*;
import package.Disjoint
public class kruskal
{
	class Node
	{
		int data;
		int weight;
	}
	int v;
	LinkedList<Node> adj[];

	public kruskal(int v)
	{
		this.v = v;
		adj = new LinkedList[];

		for(int i=0;i<this.v;i++)
		{
			adj[i] = new LinkedList<>();
		}
	}

	public void addEdge(int u, int v, int w)
	{
		Node node1 = new Node();
		node1.data = u;
		Node node2 = new Node();
		node2.data = v;
		node1.weight = node2.weight = w;
		adj[node1].add(node2);
	}

	public void kruskal_mst()
}