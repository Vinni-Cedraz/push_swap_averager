#include "../include/averager.h"

bool SEGFAULT = 0;

static void build_test3_string(char memtest[], int i, int **table) {
    sprintf(memtest, "(./push_swap %d %d %d | wc -l) 2>&1", table[i][0],
            table[i][1], table[i][2]);
}

static void build_memtest3_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "(valgrind -q ./push_swap %d %d %d |"
            "./checker_linux %d %d %d) 2>&1",
            table[i][0], table[i][1], table[i][2], table[i][0], table[i][1],
            table[i][2]);
}

static void build_memtest5_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "(valgrind -q ./push_swap %d %d %d %d %d | "
            "./checker_linux %d %d %d %d %d) 2>&1",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4]);
}

static void build_memtest10_string(char memtest[], int i, int **table) {
    sprintf(memtest,
            "(valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d | "
            "./checker_linux %d %d %d %d %d %d %d %d %d %d) 2>&1",
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
            table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
            table[i][5], table[i][6], table[i][7], table[i][8], table[i][9]);
}

static void build_memtest15_string(char memtest[], int i, int **table) {
    sprintf(
        memtest,
        "(valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "|"
        " ./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d) 2>&1",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14]);
}

static void build_memtest20_string(char memtest[], int i, int **table) {
    sprintf(
        memtest,
        "(valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d |"
        "./checker_linux %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d) 2>&1",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19]);
}

static void build_memtest100_string(int i, int **table, char command[]) {
    sprintf(
        command,
        "(valgrind -q ./push_swap %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | ./checker_linux %d "
        "%d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d) 2>&1",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99],
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99]);
}

static void build_memtest500_string(int i, int **table, char command[]) {
    sprintf(
        command,
        "(valgrind -q ./push_swap "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d | "
        "./checker_linux "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d "
        "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d) 2>&1",
        table[i][0], table[i][1], table[i][2], table[i][3], table[i][4],
        table[i][5], table[i][6], table[i][7], table[i][8], table[i][9],
        table[i][10], table[i][11], table[i][12], table[i][13], table[i][14],
        table[i][15], table[i][16], table[i][17], table[i][18], table[i][19],
        table[i][20], table[i][21], table[i][22], table[i][23], table[i][24],
        table[i][25], table[i][26], table[i][27], table[i][28], table[i][29],
        table[i][30], table[i][31], table[i][32], table[i][33], table[i][34],
        table[i][35], table[i][36], table[i][37], table[i][38], table[i][39],
        table[i][40], table[i][41], table[i][42], table[i][43], table[i][44],
        table[i][45], table[i][46], table[i][47], table[i][48], table[i][49],
        table[i][50], table[i][51], table[i][52], table[i][53], table[i][54],
        table[i][55], table[i][56], table[i][57], table[i][58], table[i][59],
        table[i][60], table[i][61], table[i][62], table[i][63], table[i][64],
        table[i][65], table[i][66], table[i][67], table[i][68], table[i][69],
        table[i][70], table[i][71], table[i][72], table[i][73], table[i][74],
        table[i][75], table[i][76], table[i][77], table[i][78], table[i][79],
        table[i][80], table[i][81], table[i][82], table[i][83], table[i][84],
        table[i][85], table[i][86], table[i][87], table[i][88], table[i][89],
        table[i][90], table[i][91], table[i][92], table[i][93], table[i][94],
        table[i][95], table[i][96], table[i][97], table[i][98], table[i][99],
        table[i][100], table[i][101], table[i][102], table[i][103],
        table[i][104], table[i][105], table[i][106], table[i][107],
        table[i][108], table[i][109], table[i][110], table[i][111],
        table[i][112], table[i][113], table[i][114], table[i][115],
        table[i][116], table[i][117], table[i][118], table[i][119],
        table[i][120], table[i][121], table[i][122], table[i][123],
        table[i][124], table[i][125], table[i][126], table[i][127],
        table[i][128], table[i][129], table[i][130], table[i][131],
        table[i][132], table[i][133], table[i][134], table[i][135],
        table[i][136], table[i][137], table[i][138], table[i][139],
        table[i][140], table[i][141], table[i][142], table[i][143],
        table[i][144], table[i][145], table[i][146], table[i][147],
        table[i][148], table[i][149], table[i][150], table[i][151],
        table[i][152], table[i][153], table[i][154], table[i][155],
        table[i][156], table[i][157], table[i][158], table[i][159],
        table[i][160], table[i][161], table[i][162], table[i][163],
        table[i][164], table[i][165], table[i][166], table[i][167],
        table[i][168], table[i][169], table[i][170], table[i][171],
        table[i][172], table[i][173], table[i][174], table[i][175],
        table[i][176], table[i][177], table[i][178], table[i][179],
        table[i][180], table[i][181], table[i][182], table[i][183],
        table[i][184], table[i][185], table[i][186], table[i][187],
        table[i][188], table[i][189], table[i][190], table[i][191],
        table[i][192], table[i][193], table[i][194], table[i][195],
        table[i][196], table[i][197], table[i][198], table[i][199],
        table[i][200], table[i][201], table[i][202], table[i][203],
        table[i][204], table[i][205], table[i][206], table[i][207],
        table[i][208], table[i][209], table[i][210], table[i][211],
        table[i][212], table[i][213], table[i][214], table[i][215],
        table[i][216], table[i][217], table[i][218], table[i][219],
        table[i][220], table[i][221], table[i][222], table[i][223],
        table[i][224], table[i][225], table[i][226], table[i][227],
        table[i][228], table[i][229], table[i][230], table[i][231],
        table[i][232], table[i][233], table[i][234], table[i][235],
        table[i][236], table[i][237], table[i][238], table[i][239],
        table[i][240], table[i][241], table[i][242], table[i][243],
        table[i][244], table[i][245], table[i][246], table[i][247],
        table[i][248], table[i][249], table[i][250], table[i][251],
        table[i][252], table[i][253], table[i][254], table[i][255],
        table[i][256], table[i][257], table[i][258], table[i][259],
        table[i][260], table[i][261], table[i][262], table[i][263],
        table[i][264], table[i][265], table[i][266], table[i][267],
        table[i][268], table[i][269], table[i][270], table[i][271],
        table[i][272], table[i][273], table[i][274], table[i][275],
        table[i][276], table[i][277], table[i][278], table[i][279],
        table[i][280], table[i][281], table[i][282], table[i][283],
        table[i][284], table[i][285], table[i][286], table[i][287],
        table[i][288], table[i][289], table[i][290], table[i][291],
        table[i][292], table[i][293], table[i][294], table[i][295],
        table[i][296], table[i][297], table[i][298], table[i][299],
        table[i][300], table[i][301], table[i][302], table[i][303],
        table[i][304], table[i][305], table[i][306], table[i][307],
        table[i][308], table[i][309], table[i][310], table[i][311],
        table[i][312], table[i][313], table[i][314], table[i][315],
        table[i][316], table[i][317], table[i][318], table[i][319],
        table[i][320], table[i][321], table[i][322], table[i][323],
        table[i][324], table[i][325], table[i][326], table[i][327],
        table[i][328], table[i][329], table[i][330], table[i][331],
        table[i][332], table[i][333], table[i][334], table[i][335],
        table[i][336], table[i][337], table[i][338], table[i][339],
        table[i][340], table[i][341], table[i][342], table[i][343],
        table[i][344], table[i][345], table[i][346], table[i][347],
        table[i][348], table[i][349], table[i][350], table[i][351],
        table[i][352], table[i][353], table[i][354], table[i][355],
        table[i][356], table[i][357], table[i][358], table[i][359],
        table[i][360], table[i][361], table[i][362], table[i][363],
        table[i][364], table[i][365], table[i][366], table[i][367],
        table[i][368], table[i][369], table[i][370], table[i][371],
        table[i][372], table[i][373], table[i][374], table[i][375],
        table[i][376], table[i][377], table[i][378], table[i][379],
        table[i][380], table[i][381], table[i][382], table[i][383],
        table[i][384], table[i][385], table[i][386], table[i][387],
        table[i][388], table[i][389], table[i][390], table[i][391],
        table[i][392], table[i][393], table[i][394], table[i][395],
        table[i][396], table[i][397], table[i][398], table[i][399],
        table[i][400], table[i][401], table[i][402], table[i][403],
        table[i][404], table[i][405], table[i][406], table[i][407],
        table[i][408], table[i][409], table[i][410], table[i][411],
        table[i][412], table[i][413], table[i][414], table[i][415],
        table[i][416], table[i][417], table[i][418], table[i][419],
        table[i][420], table[i][421], table[i][422], table[i][423],
        table[i][424], table[i][425], table[i][426], table[i][427],
        table[i][428], table[i][429], table[i][430], table[i][431],
        table[i][432], table[i][433], table[i][434], table[i][435],
        table[i][436], table[i][437], table[i][438], table[i][439],
        table[i][440], table[i][441], table[i][442], table[i][443],
        table[i][444], table[i][445], table[i][446], table[i][447],
        table[i][448], table[i][449], table[i][450], table[i][451],
        table[i][452], table[i][453], table[i][454], table[i][455],
        table[i][456], table[i][457], table[i][458], table[i][459],
        table[i][460], table[i][461], table[i][462], table[i][463],
        table[i][464], table[i][465], table[i][466], table[i][467],
        table[i][468], table[i][469], table[i][470], table[i][471],
        table[i][472], table[i][473], table[i][474], table[i][475],
        table[i][476], table[i][477], table[i][478], table[i][479],
        table[i][480], table[i][481], table[i][482], table[i][483],
        table[i][484], table[i][485], table[i][486], table[i][487],
        table[i][488], table[i][489], table[i][490], table[i][491],
        table[i][492], table[i][493], table[i][494], table[i][495],
        table[i][496], table[i][497], table[i][498], table[i][499], table[i][0],
        table[i][1], table[i][2], table[i][3], table[i][4], table[i][5],
        table[i][6], table[i][7], table[i][8], table[i][9], table[i][10],
        table[i][11], table[i][12], table[i][13], table[i][14], table[i][15],
        table[i][16], table[i][17], table[i][18], table[i][19], table[i][20],
        table[i][21], table[i][22], table[i][23], table[i][24], table[i][25],
        table[i][26], table[i][27], table[i][28], table[i][29], table[i][30],
        table[i][31], table[i][32], table[i][33], table[i][34], table[i][35],
        table[i][36], table[i][37], table[i][38], table[i][39], table[i][40],
        table[i][41], table[i][42], table[i][43], table[i][44], table[i][45],
        table[i][46], table[i][47], table[i][48], table[i][49], table[i][50],
        table[i][51], table[i][52], table[i][53], table[i][54], table[i][55],
        table[i][56], table[i][57], table[i][58], table[i][59], table[i][60],
        table[i][61], table[i][62], table[i][63], table[i][64], table[i][65],
        table[i][66], table[i][67], table[i][68], table[i][69], table[i][70],
        table[i][71], table[i][72], table[i][73], table[i][74], table[i][75],
        table[i][76], table[i][77], table[i][78], table[i][79], table[i][80],
        table[i][81], table[i][82], table[i][83], table[i][84], table[i][85],
        table[i][86], table[i][87], table[i][88], table[i][89], table[i][90],
        table[i][91], table[i][92], table[i][93], table[i][94], table[i][95],
        table[i][96], table[i][97], table[i][98], table[i][99], table[i][100],
        table[i][101], table[i][102], table[i][103], table[i][104],
        table[i][105], table[i][106], table[i][107], table[i][108],
        table[i][109], table[i][110], table[i][111], table[i][112],
        table[i][113], table[i][114], table[i][115], table[i][116],
        table[i][117], table[i][118], table[i][119], table[i][120],
        table[i][121], table[i][122], table[i][123], table[i][124],
        table[i][125], table[i][126], table[i][127], table[i][128],
        table[i][129], table[i][130], table[i][131], table[i][132],
        table[i][133], table[i][134], table[i][135], table[i][136],
        table[i][137], table[i][138], table[i][139], table[i][140],
        table[i][141], table[i][142], table[i][143], table[i][144],
        table[i][145], table[i][146], table[i][147], table[i][148],
        table[i][149], table[i][150], table[i][151], table[i][152],
        table[i][153], table[i][154], table[i][155], table[i][156],
        table[i][157], table[i][158], table[i][159], table[i][160],
        table[i][161], table[i][162], table[i][163], table[i][164],
        table[i][165], table[i][166], table[i][167], table[i][168],
        table[i][169], table[i][170], table[i][171], table[i][172],
        table[i][173], table[i][174], table[i][175], table[i][176],
        table[i][177], table[i][178], table[i][179], table[i][180],
        table[i][181], table[i][182], table[i][183], table[i][184],
        table[i][185], table[i][186], table[i][187], table[i][188],
        table[i][189], table[i][190], table[i][191], table[i][192],
        table[i][193], table[i][194], table[i][195], table[i][196],
        table[i][197], table[i][198], table[i][199], table[i][200],
        table[i][201], table[i][202], table[i][203], table[i][204],
        table[i][205], table[i][206], table[i][207], table[i][208],
        table[i][209], table[i][210], table[i][211], table[i][212],
        table[i][213], table[i][214], table[i][215], table[i][216],
        table[i][217], table[i][218], table[i][219], table[i][220],
        table[i][221], table[i][222], table[i][223], table[i][224],
        table[i][225], table[i][226], table[i][227], table[i][228],
        table[i][229], table[i][230], table[i][231], table[i][232],
        table[i][233], table[i][234], table[i][235], table[i][236],
        table[i][237], table[i][238], table[i][239], table[i][240],
        table[i][241], table[i][242], table[i][243], table[i][244],
        table[i][245], table[i][246], table[i][247], table[i][248],
        table[i][249], table[i][250], table[i][251], table[i][252],
        table[i][253], table[i][254], table[i][255], table[i][256],
        table[i][257], table[i][258], table[i][259], table[i][260],
        table[i][261], table[i][262], table[i][263], table[i][264],
        table[i][265], table[i][266], table[i][267], table[i][268],
        table[i][269], table[i][270], table[i][271], table[i][272],
        table[i][273], table[i][274], table[i][275], table[i][276],
        table[i][277], table[i][278], table[i][279], table[i][280],
        table[i][281], table[i][282], table[i][283], table[i][284],
        table[i][285], table[i][286], table[i][287], table[i][288],
        table[i][289], table[i][290], table[i][291], table[i][292],
        table[i][293], table[i][294], table[i][295], table[i][296],
        table[i][297], table[i][298], table[i][299], table[i][300],
        table[i][301], table[i][302], table[i][303], table[i][304],
        table[i][305], table[i][306], table[i][307], table[i][308],
        table[i][309], table[i][310], table[i][311], table[i][312],
        table[i][313], table[i][314], table[i][315], table[i][316],
        table[i][317], table[i][318], table[i][319], table[i][320],
        table[i][321], table[i][322], table[i][323], table[i][324],
        table[i][325], table[i][326], table[i][327], table[i][328],
        table[i][329], table[i][330], table[i][331], table[i][332],
        table[i][333], table[i][334], table[i][335], table[i][336],
        table[i][337], table[i][338], table[i][339], table[i][340],
        table[i][341], table[i][342], table[i][343], table[i][344],
        table[i][345], table[i][346], table[i][347], table[i][348],
        table[i][349], table[i][350], table[i][351], table[i][352],
        table[i][353], table[i][354], table[i][355], table[i][356],
        table[i][357], table[i][358], table[i][359], table[i][360],
        table[i][361], table[i][362], table[i][363], table[i][364],
        table[i][365], table[i][366], table[i][367], table[i][368],
        table[i][369], table[i][370], table[i][371], table[i][372],
        table[i][373], table[i][374], table[i][375], table[i][376],
        table[i][377], table[i][378], table[i][379], table[i][380],
        table[i][381], table[i][382], table[i][383], table[i][384],
        table[i][385], table[i][386], table[i][387], table[i][388],
        table[i][389], table[i][390], table[i][391], table[i][392],
        table[i][393], table[i][394], table[i][395], table[i][396],
        table[i][397], table[i][398], table[i][399], table[i][400],
        table[i][401], table[i][402], table[i][403], table[i][404],
        table[i][405], table[i][406], table[i][407], table[i][408],
        table[i][409], table[i][410], table[i][411], table[i][412],
        table[i][413], table[i][414], table[i][415], table[i][416],
        table[i][417], table[i][418], table[i][419], table[i][420],
        table[i][421], table[i][422], table[i][423], table[i][424],
        table[i][425], table[i][426], table[i][427], table[i][428],
        table[i][429], table[i][430], table[i][431], table[i][432],
        table[i][433], table[i][434], table[i][435], table[i][436],
        table[i][437], table[i][438], table[i][439], table[i][440],
        table[i][441], table[i][442], table[i][443], table[i][444],
        table[i][445], table[i][446], table[i][447], table[i][448],
        table[i][449], table[i][450], table[i][451], table[i][452],
        table[i][453], table[i][454], table[i][455], table[i][456],
        table[i][457], table[i][458], table[i][459], table[i][460],
        table[i][461], table[i][462], table[i][463], table[i][464],
        table[i][465], table[i][466], table[i][467], table[i][468],
        table[i][469], table[i][470], table[i][471], table[i][472],
        table[i][473], table[i][474], table[i][475], table[i][476],
        table[i][477], table[i][478], table[i][479], table[i][480],
        table[i][481], table[i][482], table[i][483], table[i][484],
        table[i][485], table[i][486], table[i][487], table[i][488],
        table[i][489], table[i][490], table[i][491], table[i][492],
        table[i][493], table[i][494], table[i][495], table[i][496],
        table[i][497], table[i][498], table[i][499]);
}

static void execute_memtest(void *args_void) {
    t_args *args = (t_args *)args_void;
    int **table = args->table;
    char buffer[10];
    char command[10000];
    FILE *output;
    int i = 1;

    dprintf(1, HBLUE "arrays of size 3\n" DEF_COLOR);
    while (table[i]) {
        build_memtest3_string(command, i, table);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        dprintf(1, BLUE "arr[%d]:" DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 3; j++) dprintf(1, "%d ", table[i][j]);
        dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR GREEN "%s" DEF_COLOR,
                buffer);
        if (!strncmp("Segmentation", buffer, 5)) {
            handle_segfault(table, 3, i);
            SEGFAULT = 1;
        };
        pclose(output);
        i++;
    }

    i = 1;
    while (table[i]) {
        build_test3_string(command, i, table);
        output = popen(command, "r");
        fgets(buffer, 10, output);
        dprintf(1, BLUE "arr[%d]:" DEF_COLOR " ./push_swap ", i);
        for (int j = 0; j < 3; j++) dprintf(1, "%d ", table[i][j]);
        dprintf(1, CYAN "	Operations: " DEF_COLOR WHITE "%s" DEF_COLOR,
                buffer);
        if (atoi(buffer) > 2) {
            dprintf(1, HRED "ERROR:	" RED
                            "exceeded the limit of operations (2)\n" DEF_COLOR);
        }
        if (!strncmp("Segmentation", buffer, 5)) {
            handle_segfault(table, 3, i);
            SEGFAULT = 1;
        };
        pclose(output);
        i++;
    }
    dprintf(1, YELLOW "checker_linux: " DEF_COLOR GREEN "OK\n" DEF_COLOR);
    dprintf(1, "\n");

    dprintf(1, WHITE "\nMEMORY AND SORTING TESTS\n" DEF_COLOR);
    dprintf(1, CYAN "	with valgrind -q \n\n\n" DEF_COLOR);
    i += 2;
    build_memtest5_string(command, i, table);
    output = popen(command, "r");
    fgets(buffer, 10, output);
    dprintf(1, HBLUE "(SIZE 5):" DEF_COLOR " ./push_swap ");
    for (int j = 0; j < 5; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR);
    fprintf_ok_ko(buffer, output, NULL);
	if (!strncmp("Segmentation", buffer, 5)) {
		handle_segfault(table, 5, i);
		SEGFAULT = 1;
	};
    pclose(output);

    i = 11;
    build_memtest10_string(command, i, table);
    output = popen(command, "r");
    fgets(buffer, 10, output);
    dprintf(1, HBLUE "(SIZE 10):" DEF_COLOR " ./push_swap ");
    for (int j = 0; j < 10; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR);
    fprintf_ok_ko(buffer, output, NULL);
	if (!strncmp("Segmentation", buffer, 5)) {
		handle_segfault(table, 10, i);
		SEGFAULT = 1;
	};
    pclose(output);

    i = 15;
    build_memtest15_string(command, i, table);
    output = popen(command, "r");
    fgets(buffer, 10, output);
    dprintf(1, HBLUE "(SIZE 15):" DEF_COLOR " ./push_swap ");
    for (int j = 0; j < 15; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR);
    fprintf_ok_ko(buffer, output, NULL);
	if (!strncmp("Segmentation", buffer, 5)) {
		handle_segfault(table, 15, i);
		SEGFAULT = 1;
	};
    pclose(output);

    i = 19;
    build_memtest20_string(command, i, table);
    output = popen(command, "r");
    fgets(buffer, 10, output);
    dprintf(1, HBLUE "(SIZE 20):" DEF_COLOR " ./push_swap ");
    for (int j = 0; j < 20; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR);
    fprintf_ok_ko(buffer, output, NULL);
	if (!strncmp("Segmentation", buffer, 5)) {
		handle_segfault(table, 20, i);
		SEGFAULT = 1;
	};
    pclose(output);

    i = 27;
    build_memtest100_string(i, table, command);
    output = popen(command, "r");
    fgets(buffer, 10, output);
    dprintf(1, HBLUE "(SIZE 100):" DEF_COLOR " ./push_swap ");
    for (int j = 0; j < 100; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR);
    fprintf_ok_ko(buffer, output, NULL);
    if (!strncmp("Segmentation", buffer, 5)) {
        handle_segfault(table, 100, i);
        SEGFAULT = 1;
    };
    pclose(output);

    i = 31;
    build_memtest500_string(i, table, command);
    output = popen(command, "r");
    fgets(buffer, 10, output);
    dprintf(1, HBLUE "(SIZE 500):" DEF_COLOR " ./push_swap ");
    for (int j = 0; j < 500; j++) dprintf(1, "%d ", table[i][j]);
    dprintf(1, YELLOW "\nchecker_linux: " DEF_COLOR);
    fprintf_ok_ko(buffer, output, NULL);
    if (!strncmp("Segmentation", buffer, 5)) {
        handle_segfault(table, 500, i);
        SEGFAULT = 1;
    };
    pclose(output);
}

int main(void) {
    t_args *args = malloc(sizeof(t_args));
    args->table = init_table();
    dprintf(1, HRED
            "\n\nMAKE SURE YOU COMPILED EVERYTHING WITH THE -O3 "
            "FLAG\n\n\n" DEF_COLOR);
    sleep(3);
    dprintf(1, WHITE "BASIC TESTS\n" DEF_COLOR);
    dprintf(1, CYAN "	with valgrind -q\n" DEF_COLOR);
    execute_memtest(args);
    dprintf(1, CYAN
            "\n\n\nIf you didnt see any valgrind messages it means no "
            "memory leaks were found in your program\n\n\n\n" DEF_COLOR);
    dprintf(1, HCYAN
            "Now, we will check sorting correctness with several different "
            "permutations...\n" DEF_COLOR);
    exaustive_test20(args);
    ft_free_arr_size((void **)args->table, 1000);
    free(args);
    dprintf(1, CYAN "no error messages will mean its OK\n\n" DEF_COLOR);
	if (SEGFAULT) {
		dprintf(1, RED "SEGFAULT DETECTED\n\n" DEF_COLOR);
		return (1);
	}
}
