import java.util.*;

public class Graph3
{
	int V;
	LinkedList<Integer> adj[];
	public Graph3(int v)
	{
		this.V = v;
		adj = new LinkedList[v];

		for(int i=0;i<v;i++)
		{
			adj[i] =  new LinkedList<Integer>();
		}
	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	public boolean checkCycleIter(int root, boolean visited[])
	{
		boolean on_stack[] = new boolean[this.V];

		Stack<Integer> stack = new Stack<>();

		for(int i=0;i<this.V;i++)
		{
			if(visited[i])
				continue;

			stack.push(i);

			while(!stack.isEmpty())
			{
				int s = stack.pop();

				if(!visited[s])
				{
					visited[s] = true;
					on_stack[s] = true;

				}
				else
				{
					on_stack[s] = false;
					stack.pop();
				}

				for(Integer n: adj[s])
				{
					if(!visited[n])
					{
						stack.push(n);
					}
					else if(on_stack[n])
					{
						return true;
					}
				}
			}
		}

		return false;
	}

	public boolean checkCycle(int root, boolean visited[], boolean recStack[])
	{
		visited[root] = true;
		Stack<Integer> s = new Stack<>();
		s.add(root);
		recStack[root] = true;

		while(!s.isEmpty())
		{
			int el = s.pop();
			if(recStack[el] == true)
			{
				return true;
			}
			else
			{
				for(Integer n: adj[el])
				{
					if(!visited[n])
					{
						s.push(n);
						visited[n] =true;
					}
				}
			}
		}

		return false;
	}

	public static void main(String args[])
	{
		Graph3 g = new Graph3(4); 
	    g.addEdge(0, 1); 
	    // g.addEdge(0, 2); 
	    g.addEdge(1, 2); 
	    // g.addEdge(2, 0); 
	    g.addEdge(2, 3); 
	    // g.addEdge(3, 3); 
	  	boolean visited[] = new boolean[4];
	  	Arrays.fill(visited, false);
	  	boolean recStack[] = new boolean[4];
	    if(g.checkCycleIter(0, visited)) 
	        System.out.println("YES"); 
	    else
	        System.out.println("NO"); 
	    
	}

}