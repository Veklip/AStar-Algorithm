# AStar-Algorithm

## searching policy in this program

```c++
put source into openlist
while(openlist is not empty){
  get point p with minimal fscore from openlist
  remove p in openlist
  add p into closelist
  for each adjacent point of p{
    If （adj is obstacle || adj is in closeList）
		{
			Continue；
		}

		If （adj is not in openlist）
		{
			add adj into openlist
		}
		Else   //adj has already in  openlist
		{
			If （original fscore of adj > fscore of adj caculating by current path）
			{
				update adj's parent link
				update adj's fscore
			}
		}
  }
}
```
