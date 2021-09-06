#include "sorts.h"
#include <vector>
#include <iostream>

using std::cout, std::endl, std::vector, std::string;

int main() {

    vector<string> tester = {
            "I said remember this moment",
            "In the back of my mind",
            "The time we stood with our shaking hands",
            "The crowds in stands went wild",
            "We were the kings and the queens",
            "And they read off our names",
            "The night you danced like you knew",
            "Our lives would never be the same",
            "You held your head like a hero",
            "On a history book page",
            "It was the end of a decade",
            "But the start of an age",
            "Long live the walls we crashed through",
            "How the kingdom lights shined just for me and you",
            "I was screaming long live all the magic we made",
            "And bring on all the pretenders",
            "One day, we will be remembered"
    };
    radix_sort(tester);


    {
        vector<vector<int>> lists;
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9});
        lists.push_back({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({0});
        lists.push_back({1, 0});
        lists.push_back({0, 1});
        lists.push_back({1, 10, 2, 9, 3, 8, 4, 7, 5, 6});
        lists.push_back({5, 1, 9, 7, 3, 6, 2, 10, 4, 8});
        lists.push_back({8, 9, 2, 10, 3, 1, 5, 4, 7, 6});
        lists.push_back({8, 9, 2, 3, 1, 5, 4, 7, 6});
        lists.push_back({1, 1, 1, 2});
        lists.push_back({1, 1, 2, 2});
        lists.push_back({0, 0});
        lists.push_back({1, 1, 1, 2, 2, 3, 3, 3, 4});
        lists.push_back({4, 3, 3, 3, 2, 2, 1, 1, 1});
        lists.push_back({3, 1, 1, 2, 4, 3, 3, 1, 2});
        lists.push_back({1, 1, 3, 2, 1, 3, 3, 2, 2, 4});
        lists.push_back({});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            insertion_sort(lists[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9});
        lists.push_back({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({0});
        lists.push_back({1, 0});
        lists.push_back({0, 1});
        lists.push_back({1, 10, 2, 9, 3, 8, 4, 7, 5, 6});
        lists.push_back({5, 1, 9, 7, 3, 6, 2, 10, 4, 8});
        lists.push_back({8, 9, 2, 10, 3, 1, 5, 4, 7, 6});
        lists.push_back({8, 9, 2, 3, 1, 5, 4, 7, 6});
        lists.push_back({1, 1, 1, 2});
        lists.push_back({1, 1, 2, 2});
        lists.push_back({0, 0});
        lists.push_back({1, 1, 1, 2, 2, 3, 3, 3, 4});
        lists.push_back({4, 3, 3, 3, 2, 2, 1, 1, 1});
        lists.push_back({3, 1, 1, 2, 4, 3, 3, 1, 2});
        lists.push_back({1, 1, 3, 2, 1, 3, 3, 2, 2, 4});
        lists.push_back({});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            heap_sort(lists[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9});
        lists.push_back({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({0});
        lists.push_back({1, 0});
        lists.push_back({0, 1});
        lists.push_back({1, 10, 2, 9, 3, 8, 4, 7, 5, 6});
        lists.push_back({5, 1, 9, 7, 3, 6, 2, 10, 4, 8});
        lists.push_back({8, 9, 2, 10, 3, 1, 5, 4, 7, 6});
        lists.push_back({8, 9, 2, 3, 1, 5, 4, 7, 6});
        lists.push_back({1, 1, 1, 2});
        lists.push_back({1, 1, 2, 2});
        lists.push_back({0, 0});
        lists.push_back({1, 1, 1, 2, 2, 3, 3, 3, 4});
        lists.push_back({4, 3, 3, 3, 2, 2, 1, 1, 1});
        lists.push_back({3, 1, 1, 2, 4, 3, 3, 1, 2});
        lists.push_back({1, 1, 3, 2, 1, 3, 3, 2, 2, 4});
        lists.push_back({});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            merge_sort(lists[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9});
        lists.push_back({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({9, 8, 7, 6, 5, 4, 3, 2, 1});
        lists.push_back({0});
        lists.push_back({1, 0});
        lists.push_back({0, 1});
        lists.push_back({1, 10, 2, 9, 3, 8, 4, 7, 5, 6});
        lists.push_back({5, 1, 9, 7, 3, 6, 2, 10, 4, 8});
        lists.push_back({8, 9, 2, 10, 3, 1, 5, 4, 7, 6});
        lists.push_back({8, 9, 2, 3, 1, 5, 4, 7, 6});
        lists.push_back({1, 1, 1, 2});
        lists.push_back({1, 1, 2, 2});
        lists.push_back({0, 0});
        lists.push_back({1, 1, 1, 2, 2, 3, 3, 3, 4});
        lists.push_back({4, 3, 3, 3, 2, 2, 1, 1, 1});
        lists.push_back({3, 1, 1, 2, 4, 3, 3, 1, 2});
        lists.push_back({1, 1, 3, 2, 1, 3, 3, 2, 2, 4});
        lists.push_back({1534, 1534, 3534, 2534, 1534, 3534, 3534, 2534, 2534, 4534});
        lists.push_back({1535, 1534, 3535, 2534, 1535, 3535, 3534, 2535, 2534, 4535});
        lists.push_back({1, 12, 132, 123, 143, 124, 1234, 1423, 1568, 9999});
        lists.push_back({9999, 1568, 1423, 1234, 124, 143, 123, 132, 12, 1});
        lists.push_back({});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            radix_sort(lists[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<string>> lists;
        lists.push_back({"abcde", "acdbe", "eabcd", "dabcd", "acdde", "abcdf", "accde"});
        lists.push_back({"a", "b", "c", "d", "e", "f"});
        lists.push_back({"a", "aa", "aaa"});
        lists.push_back({"a"});
        lists.push_back({"1", "12", "21", "2", "13", "312", "123", "322", "212", "313", "323"});
        lists.push_back({"aaa", "aaa", "bbb", "aaa", "aa"});
        lists.push_back({});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            insertion_sort(lists[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        lists.push_back({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            selection_sort(lists[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<int> sampleList = {3, 1, 2};
        shell_sort(sampleList);
        quick_sort(sampleList);
        bucket_sort(sampleList);
    }

    // TAMU Tests

    {
        vector<vector<int>> lists;
        lists.push_back({285, 414, 517, 575, 700, 1130, 1404, 1536, 1746, 1786, 2137, 2191, 2712, 3333, 3527, 3638, 3746, 3750, 3763, 3766, 3986, 4048, 4284, 4738, 4743, 4923, 4955, 5040, 5094, 5100, 5318, 5401, 5428, 5616, 5623, 5648, 5791, 6150, 6595, 6778, 6841, 7217, 7348, 7381, 7513, 7753, 8450, 8728, 9046, 9153, 9349, 9828});
        lists.push_back({9144, 9028, 8800, 7803, 7447, 7411, 5297, 5165, 4843, 4386, 4237, 4107, 3249, 3035, 2562, 2318, 2097, 197, 179, 112});
        lists.push_back({7071, 6436, 4531, 1692, 9450, 3558, 3181, 5562, 6026, 3677, 3450, 8375, 1542, 3889, 3936, 7727, 3351, 644, 7983, 1302, 4469, 4449, 252, 4614, 2408, 2370, 5744, 6321, 9602, 3066, 407, 2358, 8377, 6930, 6095, 1983, 3041, 9972, 3092, 6487, 4647, 3055, 9528, 9844, 9785, 2139, 355, 3788, 7630, 9719, 6414, 5408, 5576, 7355, 9316, 3689, 2424, 6751, 3088, 9430, 3975, 5207, 2507, 5367, 2093, 2298, 9174, 2397, 5826, 1972, 3209, 3414, 1441, 7789, 9106, 9564, 6414, 4884, 6193, 734, 4458, 1855, 7756, 1463, 1178, 6240, 53, 7708, 8047});
        lists.push_back({2478, 1466, 8583, 9434, 451, 8980, 8138, 3812, 6021, 6456, 5916, 6957, 4115, 3270, 1928, 2582, 8689, 896, 941, 4250, 9053, 6633, 6904, 6727, 2886, 5561, 4893, 3451, 7178, 482, 1592, 7512, 4481});
        lists.push_back({5772, 9923, 7720, 1001, 8667, 8218, 6732, 924, 3318, 5875, 6242, 1211, 3483, 3139, 1016, 3766, 7067, 3475, 3603, 241, 1054, 4580, 9261, 8817, 9223, 3417, 1870, 2316, 2576, 5230, 1371, 1432, 1590, 8907, 9262, 9604, 4905, 2267, 7553, 6176, 4814, 7110, 7823, 4476, 4576, 4548, 5641, 4894, 7733, 1706});

        vector<vector<string>> lists2;
        lists2.push_back({"I walked through the door with you, the air was cold", "But something 'bout it felt like home somehow", "And I left my scarf there at your sister's house", "And you've still got it in your drawer even now", "Oh, your sweet disposition and my wide-eyed gaze", "We're singing in the car, getting lost Upstate", "Autumn leaves falling down like pieces into place", "And I can picture it after all these days", "And I know it's long gone", "And that magic's not here no more", "And I might be okay", "But I'm not fine at all"});
        lists2.push_back({"This ain't for the best", "My reputation's never been worse, so", "You must like me for me...", "We can't make", "Any promises now, can we, babe?", "But you can make me a drink...", "Dive bar on the east side, where you at?", "Phone lights up my nightstand in the black", "Come here, you can meet me in the back", "Dark jeans and your Nikes, look at you", "Oh damn, never seen that color blue", "Just think of the fun things we could do"});
        lists2.push_back({"I said remember this moment", "In the back of my mind", "The time we stood with our shaking hands", "The crowds in stands went wild", "We were the kings and the queens", "And they read off our names", "The night you danced like you knew", "Our lives would never be the same", "You held your head like a hero", "On a history book page", "It was the end of a decade", "But the start of an age", "Long live the walls we crashed through", "How the kingdom lights shined just for me and you", "I was screaming long live all the magic we made", "And bring on all the pretenders", "One day, we will be remembered"});
        lists2.push_back({"I want you to know", "I'm a mirrorball", "I'll show you every version of yourself tonight", "I'll get you out on the floor", "Shimmering beautiful", "And when I break it's in a million pieces", "Hush", "When no one is around, my dear", "You'll find me on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you", "Hush", "I know they said the end is near", "But I'm still on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you"});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            insertion_sort(lists[i]);
        }
        for (size_t i = 0; i < lists2.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            insertion_sort(lists2[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({285, 414, 517, 575, 700, 1130, 1404, 1536, 1746, 1786, 2137, 2191, 2712, 3333, 3527, 3638, 3746, 3750, 3763, 3766, 3986, 4048, 4284, 4738, 4743, 4923, 4955, 5040, 5094, 5100, 5318, 5401, 5428, 5616, 5623, 5648, 5791, 6150, 6595, 6778, 6841, 7217, 7348, 7381, 7513, 7753, 8450, 8728, 9046, 9153, 9349, 9828});
        lists.push_back({9144, 9028, 8800, 7803, 7447, 7411, 5297, 5165, 4843, 4386, 4237, 4107, 3249, 3035, 2562, 2318, 2097, 197, 179, 112});
        lists.push_back({7071, 6436, 4531, 1692, 9450, 3558, 3181, 5562, 6026, 3677, 3450, 8375, 1542, 3889, 3936, 7727, 3351, 644, 7983, 1302, 4469, 4449, 252, 4614, 2408, 2370, 5744, 6321, 9602, 3066, 407, 2358, 8377, 6930, 6095, 1983, 3041, 9972, 3092, 6487, 4647, 3055, 9528, 9844, 9785, 2139, 355, 3788, 7630, 9719, 6414, 5408, 5576, 7355, 9316, 3689, 2424, 6751, 3088, 9430, 3975, 5207, 2507, 5367, 2093, 2298, 9174, 2397, 5826, 1972, 3209, 3414, 1441, 7789, 9106, 9564, 6414, 4884, 6193, 734, 4458, 1855, 7756, 1463, 1178, 6240, 53, 7708, 8047});
        lists.push_back({2478, 1466, 8583, 9434, 451, 8980, 8138, 3812, 6021, 6456, 5916, 6957, 4115, 3270, 1928, 2582, 8689, 896, 941, 4250, 9053, 6633, 6904, 6727, 2886, 5561, 4893, 3451, 7178, 482, 1592, 7512, 4481});
        lists.push_back({5772, 9923, 7720, 1001, 8667, 8218, 6732, 924, 3318, 5875, 6242, 1211, 3483, 3139, 1016, 3766, 7067, 3475, 3603, 241, 1054, 4580, 9261, 8817, 9223, 3417, 1870, 2316, 2576, 5230, 1371, 1432, 1590, 8907, 9262, 9604, 4905, 2267, 7553, 6176, 4814, 7110, 7823, 4476, 4576, 4548, 5641, 4894, 7733, 1706});

        vector<vector<string>> lists2;
        lists2.push_back({"I walked through the door with you, the air was cold", "But something 'bout it felt like home somehow", "And I left my scarf there at your sister's house", "And you've still got it in your drawer even now", "Oh, your sweet disposition and my wide-eyed gaze", "We're singing in the car, getting lost Upstate", "Autumn leaves falling down like pieces into place", "And I can picture it after all these days", "And I know it's long gone", "And that magic's not here no more", "And I might be okay", "But I'm not fine at all"});
        lists2.push_back({"This ain't for the best", "My reputation's never been worse, so", "You must like me for me...", "We can't make", "Any promises now, can we, babe?", "But you can make me a drink...", "Dive bar on the east side, where you at?", "Phone lights up my nightstand in the black", "Come here, you can meet me in the back", "Dark jeans and your Nikes, look at you", "Oh damn, never seen that color blue", "Just think of the fun things we could do"});
        lists2.push_back({"I said remember this moment", "In the back of my mind", "The time we stood with our shaking hands", "The crowds in stands went wild", "We were the kings and the queens", "And they read off our names", "The night you danced like you knew", "Our lives would never be the same", "You held your head like a hero", "On a history book page", "It was the end of a decade", "But the start of an age", "Long live the walls we crashed through", "How the kingdom lights shined just for me and you", "I was screaming long live all the magic we made", "And bring on all the pretenders", "One day, we will be remembered"});
        lists2.push_back({"I want you to know", "I'm a mirrorball", "I'll show you every version of yourself tonight", "I'll get you out on the floor", "Shimmering beautiful", "And when I break it's in a million pieces", "Hush", "When no one is around, my dear", "You'll find me on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you", "Hush", "I know they said the end is near", "But I'm still on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you"});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            heap_sort(lists[i]);
        }
        for (size_t i = 0; i < lists2.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            heap_sort(lists2[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({285, 414, 517, 575, 700, 1130, 1404, 1536, 1746, 1786, 2137, 2191, 2712, 3333, 3527, 3638, 3746, 3750, 3763, 3766, 3986, 4048, 4284, 4738, 4743, 4923, 4955, 5040, 5094, 5100, 5318, 5401, 5428, 5616, 5623, 5648, 5791, 6150, 6595, 6778, 6841, 7217, 7348, 7381, 7513, 7753, 8450, 8728, 9046, 9153, 9349, 9828});
        lists.push_back({9144, 9028, 8800, 7803, 7447, 7411, 5297, 5165, 4843, 4386, 4237, 4107, 3249, 3035, 2562, 2318, 2097, 197, 179, 112});
        lists.push_back({7071, 6436, 4531, 1692, 9450, 3558, 3181, 5562, 6026, 3677, 3450, 8375, 1542, 3889, 3936, 7727, 3351, 644, 7983, 1302, 4469, 4449, 252, 4614, 2408, 2370, 5744, 6321, 9602, 3066, 407, 2358, 8377, 6930, 6095, 1983, 3041, 9972, 3092, 6487, 4647, 3055, 9528, 9844, 9785, 2139, 355, 3788, 7630, 9719, 6414, 5408, 5576, 7355, 9316, 3689, 2424, 6751, 3088, 9430, 3975, 5207, 2507, 5367, 2093, 2298, 9174, 2397, 5826, 1972, 3209, 3414, 1441, 7789, 9106, 9564, 6414, 4884, 6193, 734, 4458, 1855, 7756, 1463, 1178, 6240, 53, 7708, 8047});
        lists.push_back({2478, 1466, 8583, 9434, 451, 8980, 8138, 3812, 6021, 6456, 5916, 6957, 4115, 3270, 1928, 2582, 8689, 896, 941, 4250, 9053, 6633, 6904, 6727, 2886, 5561, 4893, 3451, 7178, 482, 1592, 7512, 4481});
        lists.push_back({5772, 9923, 7720, 1001, 8667, 8218, 6732, 924, 3318, 5875, 6242, 1211, 3483, 3139, 1016, 3766, 7067, 3475, 3603, 241, 1054, 4580, 9261, 8817, 9223, 3417, 1870, 2316, 2576, 5230, 1371, 1432, 1590, 8907, 9262, 9604, 4905, 2267, 7553, 6176, 4814, 7110, 7823, 4476, 4576, 4548, 5641, 4894, 7733, 1706});

        vector<vector<string>> lists2;
        lists2.push_back({"I walked through the door with you, the air was cold", "But something 'bout it felt like home somehow", "And I left my scarf there at your sister's house", "And you've still got it in your drawer even now", "Oh, your sweet disposition and my wide-eyed gaze", "We're singing in the car, getting lost Upstate", "Autumn leaves falling down like pieces into place", "And I can picture it after all these days", "And I know it's long gone", "And that magic's not here no more", "And I might be okay", "But I'm not fine at all"});
        lists2.push_back({"This ain't for the best", "My reputation's never been worse, so", "You must like me for me...", "We can't make", "Any promises now, can we, babe?", "But you can make me a drink...", "Dive bar on the east side, where you at?", "Phone lights up my nightstand in the black", "Come here, you can meet me in the back", "Dark jeans and your Nikes, look at you", "Oh damn, never seen that color blue", "Just think of the fun things we could do"});
        lists2.push_back({"I said remember this moment", "In the back of my mind", "The time we stood with our shaking hands", "The crowds in stands went wild", "We were the kings and the queens", "And they read off our names", "The night you danced like you knew", "Our lives would never be the same", "You held your head like a hero", "On a history book page", "It was the end of a decade", "But the start of an age", "Long live the walls we crashed through", "How the kingdom lights shined just for me and you", "I was screaming long live all the magic we made", "And bring on all the pretenders", "One day, we will be remembered"});
        lists2.push_back({"I want you to know", "I'm a mirrorball", "I'll show you every version of yourself tonight", "I'll get you out on the floor", "Shimmering beautiful", "And when I break it's in a million pieces", "Hush", "When no one is around, my dear", "You'll find me on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you", "Hush", "I know they said the end is near", "But I'm still on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you"});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            merge_sort(lists[i]);
        }
        for (size_t i = 0; i < lists2.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            merge_sort(lists2[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }

    {
        vector<vector<int>> lists;
        lists.push_back({285, 414, 517, 575, 700, 1130, 1404, 1536, 1746, 1786, 2137, 2191, 2712, 3333, 3527, 3638, 3746, 3750, 3763, 3766, 3986, 4048, 4284, 4738, 4743, 4923, 4955, 5040, 5094, 5100, 5318, 5401, 5428, 5616, 5623, 5648, 5791, 6150, 6595, 6778, 6841, 7217, 7348, 7381, 7513, 7753, 8450, 8728, 9046, 9153, 9349, 9828});
        lists.push_back({9144, 9028, 8800, 7803, 7447, 7411, 5297, 5165, 4843, 4386, 4237, 4107, 3249, 3035, 2562, 2318, 2097, 197, 179, 112});
        lists.push_back({7071, 6436, 4531, 1692, 9450, 3558, 3181, 5562, 6026, 3677, 3450, 8375, 1542, 3889, 3936, 7727, 3351, 644, 7983, 1302, 4469, 4449, 252, 4614, 2408, 2370, 5744, 6321, 9602, 3066, 407, 2358, 8377, 6930, 6095, 1983, 3041, 9972, 3092, 6487, 4647, 3055, 9528, 9844, 9785, 2139, 355, 3788, 7630, 9719, 6414, 5408, 5576, 7355, 9316, 3689, 2424, 6751, 3088, 9430, 3975, 5207, 2507, 5367, 2093, 2298, 9174, 2397, 5826, 1972, 3209, 3414, 1441, 7789, 9106, 9564, 6414, 4884, 6193, 734, 4458, 1855, 7756, 1463, 1178, 6240, 53, 7708, 8047});
        lists.push_back({2478, 1466, 8583, 9434, 451, 8980, 8138, 3812, 6021, 6456, 5916, 6957, 4115, 3270, 1928, 2582, 8689, 896, 941, 4250, 9053, 6633, 6904, 6727, 2886, 5561, 4893, 3451, 7178, 482, 1592, 7512, 4481});
        lists.push_back({5772, 9923, 7720, 1001, 8667, 8218, 6732, 924, 3318, 5875, 6242, 1211, 3483, 3139, 1016, 3766, 7067, 3475, 3603, 241, 1054, 4580, 9261, 8817, 9223, 3417, 1870, 2316, 2576, 5230, 1371, 1432, 1590, 8907, 9262, 9604, 4905, 2267, 7553, 6176, 4814, 7110, 7823, 4476, 4576, 4548, 5641, 4894, 7733, 1706});

        vector<vector<string>> lists2;
        lists2.push_back({"I walked through the door with you, the air was cold", "But something 'bout it felt like home somehow", "And I left my scarf there at your sister's house", "And you've still got it in your drawer even now", "Oh, your sweet disposition and my wide-eyed gaze", "We're singing in the car, getting lost Upstate", "Autumn leaves falling down like pieces into place", "And I can picture it after all these days", "And I know it's long gone", "And that magic's not here no more", "And I might be okay", "But I'm not fine at all"});
        lists2.push_back({"This ain't for the best", "My reputation's never been worse, so", "You must like me for me...", "We can't make", "Any promises now, can we, babe?", "But you can make me a drink...", "Dive bar on the east side, where you at?", "Phone lights up my nightstand in the black", "Come here, you can meet me in the back", "Dark jeans and your Nikes, look at you", "Oh damn, never seen that color blue", "Just think of the fun things we could do"});
        lists2.push_back({"I said remember this moment", "In the back of my mind", "The time we stood with our shaking hands", "The crowds in stands went wild", "We were the kings and the queens", "And they read off our names", "The night you danced like you knew", "Our lives would never be the same", "You held your head like a hero", "On a history book page", "It was the end of a decade", "But the start of an age", "Long live the walls we crashed through", "How the kingdom lights shined just for me and you", "I was screaming long live all the magic we made", "And bring on all the pretenders", "One day, we will be remembered"});
        lists2.push_back({"I want you to know", "I'm a mirrorball", "I'll show you every version of yourself tonight", "I'll get you out on the floor", "Shimmering beautiful", "And when I break it's in a million pieces", "Hush", "When no one is around, my dear", "You'll find me on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you", "Hush", "I know they said the end is near", "But I'm still on my tallest tiptoes", "Spinning in my highest heels, love", "Shining just for you"});

        for (size_t i = 0; i < lists.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            radix_sort(lists[i]);
        }
        for (size_t i = 0; i < lists2.size(); ++i) {
            cout << static_cast<char>('A' + i) << ": " << endl;
            radix_sort(lists2[i]);
        }
        cout << "---------------------------------------------------------------" << endl;
    }
    
    return 0;
}
