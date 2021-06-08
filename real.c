#include <stdio.h>

void A_to_B(int n)
{
    int pivot[2];
    int ra, rb, pb;

    ra = 0;
    rb = 0;
    pb = 0;
    if (n <= 3)
    {
        //simple_sort();
        return ;
    }
    // pivot[] = pick_pivot();
    // 적절한 피봇 2개 선택
    // pivot[0] - 작은 피봇 , pivot[1] - 큰 피봇
    while (n-- > 0)
    {
        if (a->num >= pivot[1])          // [3]
        {
            ft_command("ra");
            ra++;
        }
        else                        // [2] [1]
        {
            ft_command("pb");
            pb++;
            if (b->num >= pivot[0])      // [2]
            {
                ft_command("rb");
                rb++;
            }
        }
    }

    int i;
    i = 0;
    while (i++ < ra)
        ft_command("rra");
    while (i++ < rb)
        ft_command("rrb");
    // A :: [3] [정렬]
    // B :: [2] [1] [고정]


    A_to_B();           // [3] ~> [3_1] [3_2] [3_3]
    B_to_A();           // [2]
    B_to_A();           // [1]
}


void B_to_A(int n)
{
    int pivot[2];
    int ra, rb, pb;

    ra = 0;
    rb = 0;
    pb = 0;
    if (n <= 3)
    {
        //simple_sort();
        return ;
    }
    // pivot[] = pick_pivot();
    // 적절한 피봇 2개 선택
    // pivot[0] - 작은 피봇 , pivot[1] - 큰 피봇
    while (n-- > 0)
    {
        if (b->num <= pivot[0])          // [3_1]
        {
            ft_command("rb");
            rb++;
        }
        else                        // [3_2] [3_3]
        {
            ft_command("pa");
            pa++;
            if (a->num <= pivot[1])      // [3_2]
            {
                ft_command("ra");
                ra++;
            }
        }
    }

    A_to_B();                           // [3]

    int i;
    i = 0;
    while (i++ < ra)
        ft_command("rra");
    while (i++ < rb)
        ft_command("rrb");
    // A :: [3_2] [3_3] [정렬]
    // B :: [3_1] [고정]


    A_to_B();           // [2]
    B_to_A();           // [1]
}


[3] > 큰 피봇 > [2] > 작은 피봇 > [1]
// 1~90

// 1~30 31~60 61~90

// 61~90
// 31~60 1~30

// 81~90
// 71~80 61~70 31~60 1~30

// 88 89 90
// 87 86 85 84 83 82 81 ~~~~ 1~30

// 80-90
//