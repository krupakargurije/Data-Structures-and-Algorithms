class Solution
{
public:
    bool hasValidPath(const std::vector<std::vector<char>>& g) const noexcept
    {
        const size_t h = g.size();
        const size_t w = g[0].size();
        std::bitset<128> dp[2][101]{};
        dp[0][1] = 1u;
        for (size_t y = 0; y != h; ++y)
        {
            auto& prev = dp[y & 1];
            auto& curr = dp[(y + 1) & 1];
            for (size_t x = 0; x != w; ++x)
            {
                auto p = curr[x] | prev[x + 1];
                if (g[y][x] == '(')
                {
                    curr[x + 1] = p << 1;
                }
                else
                {
                    curr[x + 1] = p >> 1;
                }
            }
        }
        return dp[h & 1][w][0];
    }
};