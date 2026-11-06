class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        winner = 0 
        for x in range(n):
            winner = (winner+k)%(x+1)

        return winner+1    
        