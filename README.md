# Automata Theory and Formal Languages Projects

## Content:
    - Deterministic finite automaton
    	- DFA input file validation
	- DFA word acceptance
    - Nondeterministic finite automaton
	- NFA & ε-NFA input file validation
	- NFA & ε-NFA word acceptance
	- NFA to DFA conversion
    - DFA Minimization
    	- Myhill-Nerode theorem
	- Dead states elimination
    - Context-Free Grammar
    	- CFG input file validation
    - Turing Machine
    	- TM input file validation
	- TM word acceptance


# PROJECT 1 (DFA validation & acceptance)

## DFA input file validation

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project1 (DFA)** folder path.
3. Use command "g++ dfa_parser_engine.cpp -o dfa_parser_engine.exe".
4. Use command "dfa_parser_engine.exe \<input file name\>".

## DFA input file validation + word acceptance

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project1 (DFA)** folder path.
3. Use command "g++ dfa_acceptance_engine.cpp -o dfa_acceptance_engine.exe".
4. Use command "dfa_acceptance_engine.exe \<input file name\> \<word to verify\>".


# PROJECT 2 (NFA and ε-NFA validation & acceptance + NFA to DFA conversion)

## NFA input file validation

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project2.1 (NFA)** folder path.
3. Use command "g++ nfa_parser_engine.cpp -o nfa_parser_engine.exe".
4. Use command "nfa_parser_engine.exe \<input file name\>".

## NFA input file validation + word acceptance

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project2.1 (NFA)** folder path.
3. Use command "g++ nfa_acceptance_engine.cpp -o nfa_acceptance_engine.exe".
4. Use command "nfa_acceptance_engine.exe \<input file name\> \<word to verify\>".


## NFA to DFA conversion

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project2.2 (NFA to DFA)** folder path.
3. Use command "g++ nfa_conversion_engine.cpp -o nfa_conversion_engine.exe".
4. Use command "nfa_conversion_engine.exe \<input file name\>.


## ε-NFA input file validation + word acceptance

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project2.3 (Epsilon NFA)** folder path.
3. Use command "g++ e_nfa_acceptance_engine.cpp -o e_nfa_acceptance_engine.exe".
4. Use command "e_nfa_acceptance_engine.exe \<input file name\> \<word to verify\>".


# PROJECT 3 (DFA Minimization)

## Minimization to the smallest DFA with the same level of completeness (Myhill-Nerode theorem)

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project3 (DFA Minimization)** folder path.
3. Use command "g++ dfa_minimization_engine.cpp -o dfa_minimization_engine.exe".
4. Use command "dfa_minimization_engine.exe \<input file name\>".


## Minimization to the smallest (potentially) incomplete DFA (Myhill-Nerode theorem + dead states elimination)

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project3 (DFA Minimization)** folder path.
3. Use command "g++ adv_dfa_minimization_engine.cpp -o adv_dfa_minimization_engine.exe".
4. Use command "adv_dfa_minimization_engine.exe \<input file name\>".


# Project 5 (CFG)

## CFG input file validation 
To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project5 (CFG)**, then **CFG validator** folder path.
3. Use command "python CFG_validator.py \<config file name\>".

In our case, the command will be "python CFG_validator.py cfg_config_file.txt".

Format of input file:
```
//
//   Comment 0
//
Variables:
    A
    B
End
//
//   Comment 1
//
Sigma:
	0
	1
	#
End
//
//   Comment 2
//
Rules:
    A, 0A1
    A, B
    B, #
    B, e
End
//
//   Comment 3
//
Start variable:
    A
End
//
//   Comment 4
//
```


# Project 6 (Turing Machine)

## Turing Machine input file validation 

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project6 (Turing Machine)**, then **TM Validation** folder path.
3. Use command "python tmValidation.py \<config file name\>".

In our case, the command will be "python tmValidation.py configFile.txt".

Format of input file:
```
#
#   Comment 0
#
States:
	q1
	...
	...
	...
	qn
	(restul starilor)
	q_accept
	q_reject
END
#
#   Comment 1
#
Sigma:
	0
	...
	...
	(restul simbolurilor din alfabet)
End
#
#   Comment 2
#
Gamma:
	0
	x
	_
	...
	...
	(restul simbolurilor din gamma)
End
#
#   Comment 3
#
Transitions:
	forma: stare_curenta stare_urmatoare simbol_citit simbolul_care_trebuie_pus_pe_banda R/L
	q1 q2 0 _ R
	q2 q2 x e R
	q5 q2 _ e R
	q5 q5 0 e L
	q5 q5 x e L
	q3 q5 _ e L
	q3 q3 x e R
	q2 q3 0 x R
	q3 q4 0 e R
	q4 q3 0 x R
	q4 q4 x e R
	q2 q_accept _ e R
	q1 q_reject _ e R
	q1 q_reject x e R
	q4 q_reject _ e R
	....
	(restul tranzitiilor)
End
#
#   Comment 4
#
Start state:
    q1
End
#
#   Comment 5
#
Accept state:
    q_accept
End
#
#   Comment 6
#
Reject state:
    q_reject
End
```

## Turing Machine input file validation + word acceptance

To run the program, follow these steps:

1. Open CMD.
2. Use *cd* to reach the **Project6 (Turing Machine)**, then **TM Acceptance** folder path.
3. Use command "python tmAcceptance.py \<config file name\> \<input file for string\>".


In our case, the command will be "python tmAcceptance.py configFile.txt input.txt".


**Our Turing Machine was created to describe the language L = {w | w contains 2<sup>n</sup> number of 0’s, n >= 0} over the alphabet {0}.**
