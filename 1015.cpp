#includeiostream
#includeclimits
#includevector
#includeset
#includealgorithm
using namespace std;

vectorpairint, int createSkyline(vectorvectorint & buildings)
{
 
     use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
        vectorpairint, int walls, ans;                   first x, second height
        for (auto b  buildings) {
             push in left  right walls
             let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                    sort walls
        
        multisetint leftWallHeights = {0};                 keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                         current max height among leftWallHeights
        for (auto w  walls) {
            if (w.second  0) {                              it's a left wall, insert the height
                leftWallHeights.insert(-w.second);
            } else {                                         it's a right wall, delete the height
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            
            if (leftWallHeights.rbegin() != top) {          mark a skyline point if top changes
                ans.push_back(make_pair(w.first, top = leftWallHeights.rbegin()));
            }
        }
        
        return ans;
}

void func(vectorvectorint buildings)
{
    vectorpairint, int ans = createSkyline(buildings);
    for (auto it  ans) {
        coutit.first it.secondendl;
    }
}

int main()
{
    const int tuple_size = 3;
    int n;
    cinn;
    vectorvectorint buildings;
    for(int i=0;in;i++)
    {
        vectorint building(3);
        for(int j=0;jtuple_size;j++)
        {
            cinbuilding[j];
        }
        buildings.push_back(building);
    }
    func(buildings);
    return 0;
}