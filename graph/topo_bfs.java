import java.util.*;

public class topo_bfs
{
	int v;
	LinkedList<Integer> adj[];

	public topo_bfs(int v)
	{
		this.v = v;
		adj = new LinkedList[this.v];

		for(int i=0;i<v;i++)
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

		int indeg[] = new int[this.v];

		for(int i=0;i<this.v;i++)
		{
			for(Integer n: adj[i])
				indeg[n]++;
		}

		Queue<Integer> queue = new LinkedList<>();
		for(int i=0;i<this.v;i++)
		{
			if(indeg[i]==0)
				queue.add(i);
		}
		ArrayList<Integer> res = new ArrayList<>();
		int count=0;
		while(!queue.isEmpty())
		{
			int el = queue.poll();
			res.add(el);
			count++;

			for(Integer n: adj[el])
			{
				indeg[n] -=1;
				if(indeg[n]==0)
					queue.add(n);
			}

		}

		if(count!=this.v)
			System.out.println("There is a cycle!");
		else
		{
			for(int i=0;i<res.size();i++)
				System.out.print(res.get(i)+" ");
		}
	}

	public static void main(String args[]) 
    { 
        // Create a graph given in the above diagram 
        topo_bfs g=new topo_bfs(6); 
        g.addEdge(5, 2); 
        g.addEdge(5, 0); 
        g.addEdge(4, 0); 
        g.addEdge(4, 1); 
        g.addEdge(2, 3); 
        g.addEdge(3, 1);
        // g.addEdge(3, 5); 
        System.out.println("Following is a Topological Sort"); 
        g.toposort(); 
  
    } 

}