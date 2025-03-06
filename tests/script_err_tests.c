/*
** EPITECH PROJECT, 2024
** my radar
** File description:
** script error tests
*/

#include <criterion/criterion.h>
#include <radar.h>

// Airplane lines

Test(script_error_test, wrong_airplane_letter)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid1.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

Test(script_error_test, wrong_airplane_number)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid2.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

Test(script_error_test, extra_airplane_number)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid3.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

Test(script_error_test, insufficient_plane_number)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid4.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

// Tower lines

Test(script_error_test, wrong_tower_letter)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid5.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

Test(script_error_test, wrong_tower_number)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid6.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

Test(script_error_test, extra_tower_number)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid7.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

Test(script_error_test, insufficient_tower_number)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/invalid8.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), -1);
    free(argv);
}

// Valid scripts
Test(script_error_test, valid_script1)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/valid1.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), 0);
    free(argv);
}

Test(script_error_test, valid_script2)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/valid2.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), 0);
    free(argv);
}

Test(script_error_test, valid_script3)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/valid3.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), 0);
    free(argv);
}

Test(script_error_test, valid_script4)
{
    int argc = 2;
    char **argv = malloc(sizeof(char *) * argc);
    entities_t entities = {0};

    cr_assert_not_null(argv, "Memory allocation for argv failed");
    argv[0] = "./my_radar";
    argv[1] = "tests/test_scripts/valid4.rdr";
    cr_assert_eq(get_script_info(argc, argv, &entities), 0);
    free(argv);
}
