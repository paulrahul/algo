import heapq

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

        n = len(foods)
        # O(nlogn)        
        for i in range(n):
            f = foods[i]
            c = cuisines[i]
            r = ratings[i]

            if c not in self.cuisine_foods:
                self.cuisine_foods[c] = []

            h = self.cuisine_foods[c]
            heapq.heappush(h, (-r, f))

            self.food_to_cuisine[f] = c

        # for c in self.cuisine_foods:
        #     h = self.cuisine_foods[c]
        #     print(c)
        #     print([x for x in h])

        # print("Initialised")

    # O(N)
    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        # This one is tricky. I think the best thing to do is to
        # find the cuisine having this food. Then get that cuisine's
        # heap list, replace this particular item and heapify and
        # re-insert into the map.
        c = self.food_to_cuisine[food]

        h = self.cuisine_foods[c]
        n = len(h)
        # O(n)
        for i in range(n):
            t = h[i]
            if t[1] == food:
                t_l = list(t)
                t_l[0] = -newRating
                h[i] = tuple(t_l)
                break
        
        # O(N)
        heapq.heapify(h)
        self.cuisine_foods[c] = h
        # print([x for x in h])

    # O(1)
    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        # Simple. Just access the 0th element of cuisine.
        h =  self.cuisine_foods[cuisine]

        return h[0][1]
        

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
