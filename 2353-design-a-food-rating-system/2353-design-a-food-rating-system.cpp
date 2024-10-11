class FoodRatings {
public:
    // here naming is done with the order of storing the elements
    // if we store the rating and string unmodified then highest rated string will be present at the end of the set since set stores in increasing fashion
    // and when rating becomes equal then we need to write custom comparator to get the smallest lexicographich string
    // but we can use a trick, we can store negative of rating then this way the first element in the cuisine will be highest rated and will be lexicographically smallest

    unordered_map<string, int> food_rating;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, set<pair<int, string>>> cuisine_rating_food;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            food_rating[food] = rating;
            food_cuisine[food] = cuisine;
            cuisine_rating_food[cuisine].insert({rating * -1, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int old_rating = food_rating[food];
        food_rating[food] = newRating;

        cuisine_rating_food[cuisine].erase({-old_rating, food});
        cuisine_rating_food[cuisine].insert({newRating * -1, food});
    }
    
    string highestRated(string cuisine) {
        return cuisine_rating_food[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */