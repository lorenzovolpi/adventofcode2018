#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const int SIDE = 1000;

struct cut
{
    int i, x, y, w, h;
    cut(int i, int x, int y, int w, int h) : i(i), x(x), y(y), w(w), h(h) {}     
    cut(int i) : cut(i, 0, 0, 0, 0) {}

    void print() 
    {
        printf("#%d @ %d,%d: %dx%d", i, x, y, w, h);
    }

    static cut scan(std::string s)
    {
        int i, x, y, w, h;
        char *ch = &s[0];
        sscanf(ch, "#%d @ %d,%d: %dx%d", &i, &x, &y, &w, &h);
        cut c(i, x, y, w, h);

        return c;
    } 
};

int main()
{
    int fabric[SIDE][SIDE];
    for(int i = 0; i < SIDE; ++i) for(int j = 0; j < SIDE ; ++j) fabric[i][j] = 0; 

    std::vector<cut> cuts;
    std::ifstream in;
    in.open("../data/input01");
    while(!in.eof())
    {
        std::string s;
        std::getline(in, s);
        cut c = cut::scan(s);
        
        for(int i = c.y; i < c.y + c.h; ++i)
        {
            for(int j = c.x; j < c.x + c.w; ++j)
            {
                fabric[i][j]++;
            }
        }
        cuts.push_back(c);
    }
    in.close();

    int cnt = 0;
    for(int i=0; i<SIDE; ++i)
    {
        for(int j=0; j<SIDE; ++j)
        {
            if(fabric[i][j] > 1) cnt++;
        }
    }

    std::cout << cnt << std::endl;

    //Part 2
    cut *c;
    for(int k = 0; k<cuts.size(); ++k)
    {
        bool overlap = false;
        c = &cuts[k];
        for(int i = c->y; i < c->y + c->h && !overlap; ++i)
        {
            for(int j = c->x; j < c->x + c->w && !overlap; ++j)
            {
                if(fabric[i][j] > 1) overlap = true;
            }
        }

        if(!overlap) break;
    }

    std::cout << c->i << std::endl;
}