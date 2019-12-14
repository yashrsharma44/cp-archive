import java.util.*;

public class long_topo
{
	int v;
	LinkedList<Integer> adj[];

	public long_topo(int v)
	{
		this.v = v;
		adj = new LinkedList[this.v];

		for(int i=0;i<this.v;i++)
		{
			adj[i] = new LinkedList<>();
		}
	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	public void topo_sort(int root, Stack<Integer> stack, boolean[] visited)
	{
		visited[root] = true;

		for(Integer n: adj[root])
		{
			topo_sort(n, stack, visited);
		}

		stack.push(root);
	}

	public int longest_path()
	{
		Stack<Integer> stack = new Stack<>();
		boolean visited[] = new visited[this.v];
		
		for(int i=0;i<this.v;i++)
		{
			if(!visited)
				topo_sort(i, stack, visited);
		}

		
	}
}