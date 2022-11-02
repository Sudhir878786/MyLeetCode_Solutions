class Solution
{
    public:
        int minMutation(string start, string end, vector<string> &bank)
        {
            int count = 0;
            queue<string> q;
            unordered_set<string> vis;
            unordered_set<string> allowed;
            unordered_set<char> opt;

            for (int i = 0; i < bank.size(); i++)
            {
                allowed.insert(bank[i]);
            }

            opt.insert('A');
            opt.insert('C');
            opt.insert('T');
            opt.insert('G');

            q.push(start);
            vis.insert(start);

            while (!q.empty())
            {

                int k = q.size();

                while (k--)
                {

                    string tmp = q.front();
                    q.pop();

                    for (int j = 0; j < tmp.size(); j++)
                    {

                        for (auto x: opt)
                        {

                            string change = tmp;
                            change[j] = x;
                            if (vis.find(change) == vis.end() && allowed.find(change) != allowed.end())
                            {
                                if (change == end)
                                {
                                    return count + 1;
                                }
                                vis.insert(change);
                                q.push(change);
                            }
                        }
                    }
                }
                count++;
            }
            return -1;
        }
};