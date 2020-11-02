/*
** EPITECH PROJECT, 2020
** romain triozon
** File description:
** test_send_command
*/


#include <criterion/criterion.h>

/** 
 * NE SURTOUT PAS METTRE DE MAIN : Criterion va automatiquement créer une fonction main
 * Pour voir toute les assert et leurs options : https://github.com/Snaipe/Criterion/blob/514b4d820e2f8fb4daa2b95b69c981853656cb73/include/criterion/assert.h
 * la compilation devra étre rajouté au cmake : g++ -o unit_tests test_send_command.cpp  --coverage -lcriterion
 * Avec la compilation sité au dessus pour tester vous pouvez utiliser : "./unit_test"

int a_simple_test_to_see_how_it_works(int i)
{
    return i;
}

const  int len = 12;
Test(utils , expression_true_and_crassert_expected_true)
{
    cr_assert(a_simple_test_to_see_how_it_works(12) == len);// le test passe si la valeur 1 est égale à la valeur 2 
}

Test(utils, expression_true_and_crassert_expected_false) // ce test va fail car cr_assert s'attend à ce que l'expression  "(a_simple_test_to_see_how_it_works(12) == len)" soit fausse or ici elle est vrai
{
    cr_assert_not(a_simple_test_to_see_how_it_works(12) == len);
}

Test(utils, expression_false_and_crassert_expected_false) // ici elle passe car l'expresssion est fausse
{
    cr_assert_not(a_simple_test_to_see_how_it_works(12) != len);
}

Test(utils, example_of_multiple_assert_it_count_for_one_test_not_two) // this test should not pass because the first attend that the result is different and second one attend tha tthe build is equal
{
    cr_assert_not(a_simple_test_to_see_how_it_works(12) == len);
    cr_assert(a_simple_test_to_see_how_it_works(12) == len);
}
