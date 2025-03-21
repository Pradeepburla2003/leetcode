class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        map<string, vector<string>> recipeMap;  // Maps recipe → ingredients
        map<string, int> supplyCount;  // Tracks available ingredients

        // Store the recipe ingredients
        for (int i = 0; i < recipes.size(); i++) {
            recipeMap[recipes[i]] = ingredients[i];
        }

        // Store initial supplies
        for (const string& s : supplies) {
            supplyCount[s] = 1;
        }

        bool updated = true;
        while (updated) {  // Keep checking until no new recipes are made
            updated = false;

            for (auto it = recipeMap.begin(); it != recipeMap.end();) {
                string recipe = it->first;
                vector<string> ingredientList = it->second;
                bool canMake = true;

                // Check if all ingredients are available
                for (const string& ing : ingredientList) {
                    if (!supplyCount[ing]) {
                        canMake = false;
                        break;
                    }
                }

                if (canMake) {
                    ans.push_back(recipe);
                    supplyCount[recipe] = 1;  // Mark this recipe as available
                    updated = true;
                    it = recipeMap.erase(it);  // Remove processed recipe
                } else {
                    ++it;
                }
            }
        }

        return ans;
    }
};