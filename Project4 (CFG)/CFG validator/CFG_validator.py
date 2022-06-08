import sys


# „getSection”: funcție care returnează liniile unei anumite secțiuni în fișierul de intrare
def getSection(name, lGen):
    flag = False
    lRet = []

    for line in lGen:
        if line.lower() == name + ":":  # începutul secțiunii
            flag = True
            continue
        if line.lower() == "end":  # sfârşitul secţiunii
            flag = False
        if flag == True and line not in lRet: # dacă nu am ajuns la sfârșitul secțiunii, anexăm linia fișierului la listă
            lRet.append(line)

    return lRet


# „loadCFGFromFile”: funcție care utilizează funcția „getSection”, pentru a încărca secțiunile unui fișier de configurare CFG
# și returnați-le în liste, împreună cu un cod de eroare dacă fișierul nu este valid
def loadCFGFromFile(fileName):
    lGen = []
    errorCode = 0

    file = open(fileName)

    for line in file:
        line = line.strip()
        if len(line) > 0 and line[0] != "/":  # creăm o listă din fișierul de intrare numai cu
            lGen.append(line)                 # rânduri care sunt diferite de comentarii
                                              # astfel încât să-l putem trece la funcția „getSection”.

    variables = list(getSection("variables", lGen))  # obținerea variabilelor CFG din fișierul de configurare
    sigma = list(getSection("sigma", lGen))  # obținerea terminalelor CFG-ului din fișierul de configurare
    rules = list(getSection("rules", lGen))  # obținerea regulilor CFG din fișierul de configurare
    startVariable = list(getSection("start variable", lGen))  #obținerea variabilei de pornire a CFG din fișierul de configurare

   
    # dacă fișierul de configurare CFG nu conține exact o variabilă de pornire, returnăm un cod de eroare
    if len(startVariable) != 1:
        errorCode = 4
        return errorCode, variables, sigma, rules, startVariable
    elif len(startVariable[0]) != 1:  # dacă variabila de început nu are lungimea 1, returnăm un cod de eroare
        errorCode = 4
        return errorCode, variables, sigma, rules, startVariable

    
    # dacă fișierul de configurare CFG nu conține cel puțin o variabilă, inclusiv variabila de pornire, returnăm un cod de eroare
    if len(variables) == 0 or startVariable[0] not in variables:
        errorCode = 1
        return errorCode, variables, sigma, rules, startVariable
    else:  # dacă variabilele din fișierul de configurare CFG nu sunt majuscule sau nu au lungimea 1, returnăm un cod de eroare
        for variable in variables:
            if variable.upper() != variable or len(variable) != 1:
                errorCode = 1
                return errorCode, variables, sigma, rules, startVariable

    # dacă fișierul de configurare CFG nu conține cel puțin un terminal, returnăm un cod de eroare
    if len(sigma) == 0:
        errorCode = 2
        return errorCode, variables, sigma, rules, startVariable
    else: # dacă terminalele din fișierul de configurare CFG nu sunt litere mici sau nu au lungimea de 1, returnăm un cod de eroare
        for terminal in sigma:
            if terminal.lower() != terminal or len(terminal) != 1:
                errorCode = 2
                return errorCode, variables, sigma, rules, startVariable

   
    # dacă fișierul de configurare CFG nu conține nicio regulă, returnăm un cod de eroare
    if len(rules) == 0:
        errorCode = 3
        return errorCode, variables, sigma, rules, startVariable
    elif startVariable[0] not in rules[0].replace(",", " ").split()[0]:  # if the left side of the first rule does not contain the start variable, we return an error code
        errorCode = 3
        return errorCode, variables, sigma, rules, startVariable
    else:
        for rule in rules:
            rule = rule.replace(",", " ").split()
            if len(rule) != 2:  # dacă o regulă nu are exact două laturi, returnăm un cod de eroare
                errorCode = 3
                return errorCode, variables, sigma, rules, startVariable
            elif rule[0] not in variables:  # dacă variabila din partea stângă nu este recunoscută de CFG, returnăm un cod de eroare
                errorCode = 3
                return errorCode, variables, sigma, rules, startVariable
            else:
                for character in rule[1]: # dacă fie o variabilă, fie un terminal din partea dreaptă nu este recunoscut de CFG, returnăm un cod de eroare
                    if character not in variables and character not in sigma and character != "e":
                        errorCode = 3
                        return errorCode, variables, sigma, rules, startVariable

    file.close()

   # dacă fișierul de configurare CFG este valid, nu returnăm niciun cod de eroare
    return errorCode, variables, sigma, rules, startVariable


try:
    errorCode, variables, sigma, rules, startVariable = loadCFGFromFile(sys.argv[1])

    print()
    if errorCode == 1:
        print(f"Sectiunea \"variables\" din \"{sys.argv[1]}\" nu este valida.")
    elif errorCode == 2:
        print(f"Sectiunea \"sigma\" din \"{sys.argv[1]}\" nu este valida.")
    elif errorCode == 3:
        print(f"Sectiunea \"rules\" din \"{sys.argv[1]}\" nu este valida.")
    elif errorCode == 4:
        print(f"Sectiunea \"start variable\" din \"{sys.argv[1]}\" nu este valida.")
    else:
        print(f"The config file \"{sys.argv[1]}\" este valida!")
except:
    print("Fișierul solicitat nu există sau altceva a mers prost.")
