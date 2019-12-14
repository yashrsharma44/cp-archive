import java.util.*;

public class Graph2
{
	int V;
	LinkedList<Integer> adj[];

	public Graph2(int v)
	{
		this.V = v;
		this.adj = new LinkedList[v];

		for(int i=0;i<v;i++)
		{
			adj[i] = new LinkedList<Integer>();
		}

	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	public void getPath(int u, int v)
	{
		boolean visited[] = new boolean[this.V];
		ArrayList<Integer> localPath = new ArrayList<>();

		localPath.add(u);
		getPathAll(u, v, visited, localPath);
	}

	public void getPathAll(int u, int v, boolean[] visited, ArrayList<Integer> localPath)
	{
		// Mark the node
		visited[u] = true;

		if(u==v)
		{
			System.out.println(localPath);
		}
		else
		{
			for(int i=0;i<adj[u].size();i++)
			{
				if(!visited[adj[u].get(i)])
				{
					localPath.add(adj[u].get(i));
					getPathAll(adj[u].get(i), v, visited, localPath);
					localPath.remove(adj[u].get(i));
				}
			}
		}

		visited[u] = false;
		return;
	}

	public static void main(String args[])
	{
		Graph2 g = new Graph2(4); 
        g.addEdge(0,1); 
        g.addEdge(0,2); 
        g.addEdge(0,3); 
        g.addEdge(2,0); 
        g.addEdge(2,1); 
        g.addEdge(1,3); 
      
        // arbitrary source 
        int s = 2; 
      
        // arbitrary destination 
        int d = 3; 
      
        System.out.println("Following are all different paths from "+s+" to "+d); 
        g.getPath(s, d); 
	}
}