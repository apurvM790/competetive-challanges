from collections import deque
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        q=deque()
        vis=[[0 for i in range(len(maze[0]))] for j in range(len(maze))]
        q.append([entrance[0],entrance[1],1])
        n=len(maze)
        m=len(maze[0])
        brow=[-1,0,1,0]
        bcol=[0,1,0,-1]
        vis[entrance[0]][entrance[1]]=1
        while(q):
            val=q[0]
            q.popleft()
            row,col,time=val[0],val[1],val[2]
            #time_t=max(time_t,time)
            for i in range(4):
                trow=row+brow[i]
                tcol=col+bcol[i]
                #print((trow,tcol))
                if(trow>=0 and trow<len(maze) and tcol>=0 and tcol<len(maze[0]) and vis[trow][tcol]==0 and maze[trow][tcol]=="."):
                    if(trow==0 and tcol>=0) or (trow==n-1 and tcol>=0) or (trow>=0 and tcol==0) or (trow>=0 and tcol==m-1):
                        #print((trow,tcol))
                        return time
                    else:
                        vis[trow][tcol]=1
                        q.append([trow,tcol,time+1])
        #print(vis)
        #print(time_t)
        return -1
