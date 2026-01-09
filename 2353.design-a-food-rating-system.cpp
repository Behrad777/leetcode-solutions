#include<unordered_map>
#include<map>
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int items = (int) foods.size();
    for(int i=0; i<items; i++){
        string& food = foods[i];
        string& cuisine = cuisines[i];
        int rating = ratings[i];

        foods_to_cuisines[food] = cuisine;
        food_to_ratings[food] = rating;
        best_cuisine[cuisine].insert({-rating, food});
    }

    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foods_to_cuisines[food];
        int old_rating = food_to_ratings[food];

        auto& entry = best_cuisine[cuisine];
        entry.erase({-old_rating, food});

        food_to_ratings[food] = newRating;
        entry.insert({-newRating, food});

    }
    
    string highestRated(string cuisine) {

        auto& best = best_cuisine[cuisine];
        return best.begin()->second;
        
    }

private:
    unordered_map<string, string> foods_to_cuisines;
    unordered_map<string, int>    food_to_ratings;
    unordered_map<string, set<pair<int, string>>> best_cuisine;

};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */