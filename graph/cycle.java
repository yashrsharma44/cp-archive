import java.util.*;

// Detect cycle in a directed graph

public class cycle
{
	int V;
	LinkedList<Integer> adj[];

	public cycle(int v)
	{
		this.V = v;
		adj = new LinkedList[v];

		for(int i=0;i<v;i++)
		{
			adj[i] = new LinkedList<>();
		}
	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	// Check cycle using dfs(recursive)
	public boolean checkCycle(int root)
	{
		boolean visited[] = new boolean[this.V];
		boolean recstack[] = new boolean[this.V];

		Arrays.fill(visited, false);
		Arrays.fill(recstack, false);

		// Check cycle for all vertices
		for(int i=0; i<this.V;i++)
		{

		 if(checkCycleUtil(i, visited, recstack))
		 	return true;
		}

		return false;
	}

	public boolean checkCycleUtil(int root, boolean[] visited, boolean[] recstack)
	{
		//Base case
		// If root lies in the stack and it is getting visited, then 
		// a cycle exits
		if(recstack[root])
			return true;
		// If a node is visited then dfs has been exhausted and 
		// no cycle exists for that vertex
		if(visited[root])
			return false;


		// Else mark the node visited and add them to
		// recStack
		recstack[root] = true;
		visited[root] = true;

		for(Integer n: adj[root])
		{
			if(checkCycleUtil(n, visited, recstack))
			{
				return true;
			}
		}

		// Once all children have been traversed and no cycle has been 
		// found then pop out root out of call stack
		recstack[root] = false;
		// If cycle detected then one of the vertex might respond
		// else no cycle
		return false;

	}

	// Seems like an error!
	public boolean checkCycleIterUtil(int root, boolean[] visited, boolean[] recstack)
	{
		Stack<Integer> stack = new Stack<>();

		stack.push(root);
		recstack[root] = true;

		while(!stack.isEmpty())
		{
			int el = stack.pop();
			if(!visited[el])
			{
				for(Integer n: adj[el])
				{
					if(!visited[n])
					{
						visited[n] = true;
						recstack[n] = true;
						stack.push(n);
					}
					else if(recstack[n])
						return true;
				}
			}

			recstack[el] = false;
			
		}

		return false;
	}

	// DFS check cycle using iterative version

	public boolean checkCycleIter(int root)
	{
		boolean visited[] = new boolean[this.V];
		boolean recstack[] = new boolean[this.V];

		for(int i=0;i<this.V;i++)
		{
			if(checkCycleIterUtil(i, visited, recstack))
				return true;
		}

		return false;
	}

	public static void main(String[] args) 
    { 
        cycle graph = new cycle(4); 
        graph.addEdge(0, 1); 
        graph.addEdge(0, 2); 
        graph.addEdge(1, 2); 
        graph.addEdge(2, 0); 
        graph.addEdge(2, 3); 
        graph.addEdge(3, 3); 
          
        if(graph.checkCycleIter(0)) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't "
                                    + "contain cycle"); 
    }
}