class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        int n = str1.length();
        if (n != str2.length()) {
            return false;
        }
        string clockwise_rotated = str1.substr(2) + str1.substr(0, 2);
        string anticlockwise_rotated = str1.substr(n - 2) + str1.substr(0, n - 2);
        return (str2 == clockwise_rotated || str2 == anticlockwise_rotated);
    }

};