from sortedcontainers import SortedList

class FoodRatings(object):
    # O(NlogN) 
    def __init__(self, foods, cuisines, ratings):
        """
        :type foods: List[str]
        :type cuisines: List[str]
        :type ratings: List[int]
        """

        # Our core DS will be a map of cuisine to a max heap
        # of foods.
        self.cuisine_foods = {}
        # We maintain another map mapping food to cuisine.
        self.food_to_cuisine = {}
        # And one from food to rating.
        self.food_to_rating = {}

        n = len(foods)
        # O(nlogn)        
        for i in range(n):
            f = foods[i]
            c = cuisines[i]
            r = ratings[i]

            if c not in self.cuisine_foods:
                self.cuisine_foods[c] = SortedList()

            self.cuisine_foods[c].add((-r, f))
            self.food_to_cuisine[f] = c
            self.food_to_rating[f] = r

    # O(logN)
    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        # We will simply remove the previous tuple for that food, 
        # and add the new one back.
        c = self.food_to_cuisine[food]
        old_rating = self.food_to_rating[food]

        self.cuisine_foods[c].remove((-old_rating, food))
        self.cuisine_foods[c].add((-newRating, food))
        self.food_to_rating[food] = newRating

    # O(logN)
    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        # Simple. Just access the 0th element of cuisine.
        sl =  self.cuisine_foods[cuisine]

        return sl[0][1]

if __name__ == "__main__":
    # Your FoodRatings object will be instantiated and called as such:
    obj = FoodRatings(
        ["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], 
        ["korean", "japanese", "japanese", "greek", "japanese", "korean"], 
        [9, 12, 8, 15, 14, 7]
    )
    print(obj.highestRated("korean"))
    print(obj.highestRated("japanese"))

    obj.changeRating("sushi", 16)
    print(obj.highestRated("japanese"))
    obj.changeRating("ramen", 16)
    print(obj.highestRated("japanese"))
