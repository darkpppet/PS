#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> pokemons(nums.begin(), nums.end());
    
    return min(pokemons.size(), nums.size() / 2);
}