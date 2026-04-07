cse@ubuntu:~/IS023$ gedit rsa.c
^C
cse@ubuntu:~/IS023$ gcc rsa.c -o rsa -lm
cse@ubuntu:~/IS023$ ./rsa

ENTER FIRST PRIME NUMBER
7

ENTER ANOTHER PRIME NUMBER
19

ENTER MESSAGE
4

POSSIBLE VALUES OF e AND d ARE

5	65
11	59
13	25
17	89
23	47
29	41
31	7
37	73
41	29
THE ENCRYPTED MESSAGE IS

THE DECRYPTED MESSAGE IS
4
cse@ubuntu:~/IS023$ gcc DVR_algo.c -o DVR_algo
cse@ubuntu:~/IS023$ ./DVR_algo
Enter number of nodes (less than 10): 3

Enter distance from node 1 to other nodes
Enter 999 if there is no direct route
Enter distance to node 2: 2
Enter distance to node 3: 5

Enter distance from node 2 to other nodes
Enter 999 if there is no direct route
Enter distance to node 1: 2
Enter distance to node 3: 3

Enter distance from node 3 to other nodes
Enter 999 if there is no direct route
Enter distance to node 1: 5
Enter distance to node 2: 3

Initial Routing Tables:

Routing table for node 1:
Dest	Dist	NextHop
1	0	1
2	2	2
3	5	3

Routing table for node 2:
Dest	Dist	NextHop
1	2	1
2	0	2
3	3	3

Routing table for node 3:
Dest	Dist	NextHop
1	5	1
2	3	2
3	0	3

Routing Tables After Distance Vector Algorithm:

Routing table for node 1:
Dest	Dist	NextHop
1	0	1
2	2	2
3	5	3

Routing table for node 2:
Dest	Dist	NextHop
1	2	1
2	0	2
3	3	3

Routing table for node 3:
Dest	Dist	NextHop
1	5	1
2	3	2
3	0	3

Do you want to find shortest path? (y/n): y
Enter source and destination nodes: 1 3
Shortest path cost from 1 to 3 is: 5

Do you want to find shortest path? (y/n): y
Enter source and destination nodes: 2 3
Shortest path cost from 2 to 3 is: 3

Do you want to find shortest path? (y/n): n
cse@ubuntu:~/IS023$ 
