cmake_minimum_required(VERSION 3.7)
project(ed2_trab_1_runa)
project(ed2_trab_1_runb)
project(ed2_trab_2_bintree)
project(ed2_trab_2_hash)
project(exercicio3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_runa
        ed2_trab_1/runa/io_arq.c
        ed2_trab_1/runa/io_arq.h
        ed2_trab_1/runa/lib_sort.c
        ed2_trab_1/runa/lib_sort.h
        ed2_trab_1/runa/main.c
        ed2_trab_1/runa/rand_file.c
        ed2_trab_1/runa/rand_file.h)

set(SOURCE_FILES_runb
        ed2_trab_1/runb/io_arq.c
        ed2_trab_1/runb/io_arq.h
        ed2_trab_1/runb/lib_sort.c
        ed2_trab_1/runb/lib_sort.h
        ed2_trab_1/runb/main.c
        ed2_trab_1/runb/rand_file.c
        ed2_trab_1/runb/rand_file.h)

set(SOURCE_FILES_bintree
        ed2_trab_2/arvore/btree_unb.c
        ed2_trab_2/arvore/btree_unb.h
        ed2_trab_2/arvore/word_struct.c
        ed2_trab_2/arvore/word_struct.h
        ed2_trab_2/arvore/alphabet.h
        ed2_trab_2/arvore/alphabet.c
        ed2_trab_2/arvore/ocr_list.c
        ed2_trab_2/arvore/ocr_list.h
        ed2_trab_2/arvore/main.c)

set(SOURCE_FILES_hash
        ed2_trab_2/hash/ocr_list.c
        ed2_trab_2/hash/ocr_list.h
        ed2_trab_2/hash/reverse_hfile.c
        ed2_trab_2/hash/reverse_hfile.h
        ed2_trab_2/hash/word_struct.c
        ed2_trab_2/hash/word_struct.h
        ed2_trab_2/hash/search_rhf.c
        ed2_trab_2/hash/search_rhf.h
        ed2_trab_2/hash/alphabet.c
        ed2_trab_2/hash/alphabet.h
        ed2_trab_2/hash/main.c)
set(SOURCE_FILES_EX3
        ed2_trab_2/exercicio3/arvorebinaria.c)

add_executable(ed2_trab_1_runa ${SOURCE_FILES_runa})
target_link_libraries(ed2_trab_1_runa m)

add_executable(ed2_trab_1_runb ${SOURCE_FILES_runb})
target_link_libraries(ed2_trab_1_runb m)

add_executable(ed2_trab_2_bintree ${SOURCE_FILES_bintree})
target_link_libraries(ed2_trab_2_bintree m)

add_executable(ed2_trab_2_hash ${SOURCE_FILES_hash})
target_link_libraries(ed2_trab_2_hash m)

add_executable(exercicio3 ${SOURCE_FILES_EX3})
target_link_libraries(exercicio3 m)