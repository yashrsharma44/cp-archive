import java.util.*;

public class topo_dfs
{

	int v;
	LinkedList<Integer> adj[];

	public topo_dfs(int v)
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

	public void toposort()
	{
		boolean visited[] = new boolean[this.v];
		Arrays.fill(visited, false);
		Stack<Integer> stack = new Stack<>();

		for(int i=0;i<this.v;i++)
			if(!visited[i]) toposort_util(i, visited, stack);

		while(!stack.isEmpty())
		{
			System.out.print(stack.pop()+" ");
		}
	}

	public void toposort_util(int root, boolean[] visited, Stack<Integer> stack)
	{
		visited[root] = true;

		for(Integer n: adj[root])
		{
			if(!visited[n])
			{
				toposort_util(n, visited, stack);
			}

		}

		stack.push(root);
	}

	public static void main(String args[])
	{
		topo_dfs g = new topo_dfs(6); 
        g.addEdge(5, 2); 
        g.addEdge(5, 0); 
        g.addEdge(4, 0); 
        g.addEdge(4, 1); 
        g.addEdge(2, 3); 
        g.addEdge(3, 1); 
  
        System.out.println("Following is a Topological " + 
                           "sort of the given graph"); 
        g.toposort(); 
	}
}