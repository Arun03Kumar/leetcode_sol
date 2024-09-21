class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
            nums = [str(i) for i in range(1, n + 1)]
    
            # Sort numbers lexicographically by modifying the sort key
            nums.sort(key=lambda x: x)
            
            # Convert the sorted string numbers back to integers
            return list(map(int, nums))
        