/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例 1:
输入：s = "abaccdeff"
输出：'b'

示例 2:
输入：s = "" 
输出：' '
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // char firstUniqChar(string s) {
        
    //     if(s.empty()){
    //         return ' ';
    //     }
    //     int showOrder = 1;
    //     int alpha[26] = {0};
    //     int order[26] = {0};
    //     for(auto c : s){
    //         char curChar = c - 'a';
    //         alpha[curChar] = alpha[curChar] + 1;
    //         int times = alpha[curChar] ;
    //         if(times > 1){
    //             continue;;
    //         }
    //         order[curChar] = showOrder++;
    //     }
    //     char pos = 27;
    //     char reti = -1;
    //     for(int i = 0; i < 26; ++i){
    //         if(order[i] > 0 && 1 == alpha[i]){
    //             if(order[i] < pos){
    //                 pos = order[i];
    //                 reti = i;
    //             }
    //         }
    //     }

    //     return reti == -1 ? ' ' : ('a' + reti);
    // }




    char firstUniqChar(string s) {
        unordered_map<char ,int > position;
        for(int i = 0; i < s.size(); ++i){
            if(position.count(s[i])){
                position[s[i]] = -1;
            }
            else {
                position[s[i]] = i;
            }
        }

        int first = s.size();
        for(auto iter : position){
            if(iter.second != -1 && iter.second < first){
                first = iter.second;
            }
        }
        return first == s.size() ? ' ' : s[first];
    }


    char firstUniqChar1(string s) {
        int alpha[26] = {0};
        for(auto c : s){
            alpha[c - 'a']++;
        }
        for(auto c : s){
            if(1 == alpha[c - 'a']) return c;
        }
        return ' ';
    }
};

int main(int argc, char *argv[]){
    std::string s = "jnaprrmwbbujwrgqqtccvkjvxwiimcvmokrdsbgpubcwlveeqeprvoofeepsntdrujehsthrdwunjfedhltnarwsqjxbtuwnnkklsqqmhxthicnwthvenkcvuxhxvpxihelaqariwlxtamqmocwawtcnbmilvswcurgffljwjlhbjknfpkwqckvtfbjwsosetpttjabnjxdcmwtcnievjilfcgtxmdmwmheivjrfvxvnxosrsmiwtvgnwdnwtbtogrwwxuhpetcdmttnvgttxilclxiuhpaodvmnbkwkakncbvwdgwfmitvfamuxapsfsculbtmwqvteqmsvndnctebfvaqkghculsgcjoctdmhaxqasspmermcsbencbaabxdlkxfpcdpxhaaxdnabtclwfwpcrrstxeodjnoechotqkvqoxovnoqvflligxumlttvbccimhqelfxlnotqvwfbkqogjjisxujsjgrehlosbiwpqtoraqihuvkvtaugcirbkrthlmjernseopgqansjutvvtfjxufudllhkaqgtldcupaexegdpbqxvrgxownqameonhaqwxtxetaitmctblfcfwvfdhwghvejhpuwootbxkvkhiarwlcegbrffpcfixtgbqfpthuqknrrbrkpwqqpakrnepxhmrsvktrmudomimlxjhhlkknbtspocopsdlxqtxcnjabnhnksqaxocsltfhcqmmrhmotndmwseqgshsitfgcxfhjebektvrfoqbhfdlxlkdlebsubsiiqerwwngxwlotppejqddepopkdfwoomxrpgjmhbhblwslrqidgsuexnwbpkfgbnknwuokahoiqhofvtmdxjhbtkqcpbpubnbutvqibeuewobrmbidsptstdlenbeqpuewwcinkshfncdhesvsqfahharpptnddjmtjtetsbbeeduhvvsirsoiwcjkwpjleeautxhjlbsxntfcjdpmfhwfbbehkurjuoihdhoitbiawhnggtfielhwrubvcctwbpvocstgdjnfisevfgstghcddmiuqtramowhqrnelsratclnwdjvktfvcijmcudbvmlundeckmsxghjqblpxbodknbvvbqxheivtqrbrcosmdsomwwwplrbldplinnxuqdlgkcthbbbwqtllmlngatrjfrmlwlswlmfmexkgquvuobxmflmupncsdhgxttrplmevmihmhaaafnswpnmccweivtlnwmdgbdwbsmbdwejjfovtdsuoxhqctsdlnqadvioaimqrejrhwvgcijmchiepmxmdjujwotjcexnidhpchsatatnucadrbhilrkuxogbxxgpprvdcjmagjaowxpcpsvpnxceolpfhkboopmniudiluxxxqpdbpppqjuglggvcspdnmtwcaqplrbjodfnpqvctjouwhesqsiuuktnrelveavtvjerbmixantnagalcifutptcncdlxrdvtkcopmipwvjrhktrwggikfmghibimdfxqfpujburftrbeensocscrcoafhefuxrsumudxavvvvsequnaavkrqwiabhnqnfhvhnjmrestgnmcbkedognnpdcpsqetbfabbrvwameeqbburorboxmxhxfuxjinxxefkibbspdxdkprpavukwxwgmrxktkhgckrtsuwagofqhojspxtjevkwinbsojaaptvkhpmtjvunkpfeeqhljoefmsbxkgieowsiojtkarotjkeuhqxqfelfhqxrhqqspmxwqlmulcttfookqwlqiehfdgdifixskmusnfoljxbdoddohtttrjrmweomtfvupxsovgbwljcnmtualgajbbqebdpvcasivvaaioomrawaxdiavabkquuumlxdsjxwfvwcvhmxldtlogagnixwwdgmpluodptghxvtnolorktqcskslhavlvmmkmigvtxqlmdtawtrsofwlpbvxnhaouquewdmhubfqulcwffahhsfrwkvibrnjvsmoqegktllqxshxlqmrmrvmhhlqlqokdreaklogxftrdsmcbfdnocwdjxqfutjclfesniktbfomtcrbxsowmfqxvckaukqiqofmbuubrncjnlekmjntptlicrtisnboqvfnffkxgvrxbtwgacjtxthwrtkxxngklbfgkwgpatkaruxmfdahtgmbbawtlcwfscwhpuxxqjuscwhgjguhlclilijfvcjhvroinjvigwropipseddtabcfxecfvhxidnpjdeajktaunsfkxqptcddwutbteaqanwqjkoaeshbeputljhpwqwemcogpswmocviksovpjkmvdxxidasvdupxturqoxllljbksmhtvejrjslqfbcqtncoevkqbofhpscstqwqgoiocfgsoegxxxxtirrfsikkxitjmdkgwhrvwihipiocpufefjohcpsetmebgumvsafwmeiqxwsimductmkirsgmsnnaqtkmuxkavqqtpnclgventdlpojmunegidbvemprfifxipngbebvmnusdbvgstihxwvwfkvttwcfbggodhphbibafmvswfjindpdxvtwtxpsuejliohsknsdfejsccxsmhqwsvaufkugctndkcsgilfvdmcuvtdtcmxofletixkjtisxxtptltmvgjhcgpufbcmtchxvgpaepgjqqixjlegsqgatoiswxiauxqcjncpvncrenrrjxpuwhjfxvtoafhctnxfpwxvvxxkngpvrimnqecpodkpbcxcptlohrhmvllfstclkpkrixkgqivftapqqlnpiocutsojctjunkcbghjavtlbfvhvwlehumodbmboppvpbbddkgohfvfcociarurptuwtfiuvapgungwkmsckaoliqhssrgunlhqujqwefdtdlpsleuvbgwedsmukpbmundvumcqowdmnsfiikuffxfquejxqbfsrrqufohrqlgksbqxagjnnmkqswvtmijnwpawwxpsuuovakialjnlclguoajoxfwgsabcaxcljbrmjuvlkjwicobdhcndioemfcujkghlasiqepgpuivlhltgvnbqhvtqqpcsuupcxxkiktnvbucnammeqhvovqdssnaowbsbqbbnbriekhnnoxmwjjiebblrdgjnjvqilolxtxavghfmqokuhmdltpfnurtoeijowxrfigmxfomboaxvcgokdchiefachlvelvlppwwtativbfljlrrccbcpdewqlelcchroqiujgwcqqvwkjdmkpgwfjvwjxumhjmdclchahhsbtixfuwgtdqcihapeeeqlcgqsbwhbdwpacwifnrrfnxpievlcqshhmejxjsutttdxoxhalmthfuwwbeitfajlinobdivxgoudwtvgoonkdfvkvnxocnfwnthxppuuvhdhlssawjovqdmlqailiaejlvubgwpthwijdvwgeuardgnrcvluodwdtdmqapxlettbasqhpxjnvhoouvqomndflnbedjmfuhlikkbdqkdkeurangwmlothgtbmjmgjaqbgqgrmogmxkpehfkwejwfajwnbbqughqgcjeihbrmoxwpunhigrftawmesenhvbvxfqogxjuvublegupmtaltauoqaithnhbpwklskphvlkukosasdqawitfhdiduxqknojswiclotrtieqervinuhmhccrdgkucqevvikcwgtxxpxnkcbaiewoojnnuehlijretbqqsgedaxirjwrjshuramvlxiggmqfqubjlgfongqgndkdcuwsohdslcignwfxaihglrvqgjjchhbplupiusftgxvqooiqfxforvmcejemkncwfmsflidrtupttuipnjbsurlvswxddfuphlbsttnuslvaligftgermfkjfilpehqujaswfsdducaggksjugwmrijfhppjueosufhkbnfoptbgnkmucsgteeakhufrtkwtpbovnmcgwvoxxiufuaoveagxfftgcsphseqidputgaqtvvjnkjedsnmfkltranlffwukkgrmjuwxvhfefgbmvrcmvhdjfbiwjpmucrksojsfrhorufvbvnqlghexkhhkfpgoubomgxsfbgvfxqabcjotovnloaqicwlxhextxwhgltjpxgjvnwtdmaamjdsaxelaedlpmgbbjvealwknfsamihtdmphumrgqjptxcapgdweadcrqcpfvdexxgwvrbwdaiohdtsdupftoxbhwndkhtgebxxfjhbmhbchmwndtpspkileavqxjlvcaisxenthwcjlsdcamkuivfahocutmirivqxlstnnnfncelpkxrnqxhikhfbaqmsaxhwassvgtbnftngrltmvpnlduuoemwiipfxaurfjbhjmxjwfrqsrghrdnclirhlrntsjbauaowrxhiwviqfcdvskbmitwfulaqpmbqkrdgvgtbasbewqhipxqenpekbfjvoblqwfhxfiemleedvncxgudbsccolrxqahiqcudkrpsjhlqvtidkqhkupojxlvtldipqvoggjjermhfdgqcsgjelmraxpsegqcrrpkbmvhdtshmuhgqooccbjdagrqlhiggcqsednqwajefqpsnwcktlwojshoqijmveimodsooxbphqfuitjiqduasvlosjnlwnirausxdicndlilkesorqjtupmorqtfsaoajhwemdurrbcbdrxcvshvogrhohdqjkttclpvrbqkqdsesdpnfsmpjuerjvufknqacimklrmhaihfhbkwqpkavaeecdimgitqcpulclcbcalmltqhobxkjlrppaonulflkxrxvqaagdfqwbrgjjvlfutedmwhnhxjbakpvpqmdkvthunfpfduktcrmhqdbdikxcgdkqqekeddhlukiijfiapxcsekxphnogxdtucscsajfxwwvhpwwmagxekkadgmdtupicneudcnswmqoufpvoofagttlauvbsvwksrlqxkwosukkodpmgjwhgfhbgjaosssrewhnoqwqdxsbojxenkhmxjmjdnxstlberehljvlrporvcxhvkxrpwimujqrgnjemqdvdpxoiqxhtufxofkuxnqnrpsvcrckqslxfiihnoumgumpahcqetdhrwlmfopvrwuoavogchuxmbswchguhixuuedoiurlxuwcnfllnvorftanuvajaugkbtslseovbezjduqwfgaetkchmqcxpoqptrljsuvatxpoamppvwwvtdhvlmvtwcmkndsgvnxvnsedtvintfbbjxrmsawugtghrisccgdxdstjcawshkaqhpqtinfshsaowxdokhafmgfjgngnavusdcubhddnqgrxgrdrfpwwrxbjglcwiadhhroavbxfcikspweksooucvxtmljvfiaprlgpdpskfqrhcvwdlfxoppawgeulaiqcjrcoqpsujfbohwptgujmqvdsgprgbofjrdmnghbtfihxgtrjmlmguaqosekxasgciatedphqlivkxjlpvijefqhekshomntgnbqtjqljrgsabtouagpgrmjlqjougxfwjfjcwjfiqjgxnpjahtpejvvtcdrhhhlqevabclvlqksjlvulaahpuceesfibmofwfavrpguebrvetopfmmkfmmfhokbialepwhhqtrikkvxcvcdxlxfpplqspxwwsxxkfsoqqfmumgbcaahpvdkgowvgmphsrrgrmichmbfuaoslvaegcvqqjvflhqctgkbtarmxionbtkkhveifbqpxirxkgsrlbkjqmolwdmllqvbnnjnktsqbdctrkgtrkinqpphwpsicgvanictpaljijxsslmjnbvoliliocadwmsohnfasaenllrdlrlcpvitbqtpfvpuhlfmtlkwftfbcrqogmewxxkmsphufqxdflwjjdsvgqvpfllmctwvvhkjgfovfdpbammnjvvlhangmjkuwxkaknjdwcienoavbgpaujkcpdmxhkoguaagmjobqvwqfibpwartiwcjgjdboqpcdohpmcsdviqcfctiilavowmbmscebjerdraetkvkgrfifewhahugxhrrjfiqqwgteqkehxgnrbouogjevmghbcrrnevwtoewomficsoeihlwgqnigsnxoxdbqvtvdtpurvdokkmasfknojrsfisgeghksjhvwtxuotcijjjqgborhsfsjqffvwwllpmpfptotgcfgfuuwefcpdljbiftaiiuubxcjpldjwugqawvbwibaubgprtivumwtnlwbdqkjchkrqpchhgmifprksovlkdqcvgemtklblvbavodapiojnoccfxqucnshpqdmoahkjlmnruiuvfmkoochiwuhdjvulctqftfvmlbisisdcwadwoijekgmhpqhdunpqlfrdvcjklafosrtgwvartaemilsffadhgafabpapedkbsieoiqvhkrflmxmlgelshndbnhgsebtlgmnfsjooxrqmklftwjxammshukrsdewtfvomeaefjbnotxmwwiplwgskuqkrimmlxthuhgqfbifdgmdtoalbmjljoscvthwjgxjtscagwggjeajufkedpinobxppvxsohikbwegabmsbuwwxduiioiaxvxlxoecjnxtalvalkrxdhllvjaqkslevetunvufeosmximawanxgfrggpwvhsqbamsmqdjkfkdgfobflejqmfxikuufqaxiaveckqctfkcxtumpanmudqfjqbukvbbhuasvbtaxuonjbdonoewsenmscogkgxfhfflpwmcwsnwkwtobmaqchflrosahtsdrulhxrmaaxaneudvcecjuupsafneidrulpkgvrddvsgawbdkaurrikesfpismxfhpgerriibnuajiwunewwaglmckldinhoeudoxtmmmannpslwgmprponwsnlviktkmbetjdgomgngddiaorcjfqbttinxjdtuwikrvjoxaqedevfletoxluwceckquigskafafglpamrtcxbwjlskhtodfdcrqrgnbrfrrixvmevhfknsdxitldpaodvrvwbubtkuijqjnobwoebperwjxfthqckcdhaqnotikhpvcecjewnmexevjsaasqsjdnsqsckopdugdutxiabjrdmptbwevngqegjfkhfviohpbitriteavlnofrxtirtxwddgefvwtxqnthjpwfpoxjgsnmbudvmvknreiubqlfodjqgakqswiuqufbwqohqdhkdhxflufscptfkmcsfoxmdmehmwkqgivujoqorctvebcvfeqnigejxsliuhojpnvjlsmjeruoelnawqehkxqltmjlvckqlcwlasrmebjnjsnwxamsvbbsivgqbqxpkwirbhjjrejsfarhockfxlcoxtshgbuuekudwadglhmvgnjlujfarnixogoavurrqvirxoinbfcwnrvdbtoltjnnfajegbhfxqhdejpfuumfkdofnquwueqbwwurjrmqrcwruiawmejlvllcprpbfjjrxdnqgmtjguxdruehrwsgnsetiopepojokmgrmkbsgfrbrukklsfhlacoiwnxitxbnupnerqkbovlfbkgjpexieevhcicqjlajbxcomhjwhjrmcueuwpusxkwfcbnjagfftfskbhqoxheaijceweiravlkuwrsxhxtluuaiwvbxxkhkirjifkpaelftjekhgvbbrphtorpoxusbjjttrbcgxfhvsqkpmjamonbpxuxfrtjffcjirxdtpdilxlkaxsqndfupipltnwundvnxmtkptuamchbkkibtgxaijibrrutcminxcvprtigjlsjektcprtpncrchpxflofcjefsbxhujawqwbdfadbimeqwmogdjtkumilkbibintkhbgqqpfjcnwxejhinltbkbrxqgnotmdgwnkcemvlgbqfofjhdcubwxmrudxxfpjkfjtkjofhmacrsiusfoqsghlrggucnwuouwtgwwffebvvjejjsggdlqfqwxgqnauskdchfdewnviidxwmutxovdkelxvsdoboqjwguokqrlekhrotjesslqdwpghwahmkoabjmoxeoealpdgpscpppghxatwomumouhdcfeulnamtbfawgewvpoonhpkqxuktsgcxoqidowiswwtbxtauehrkurbwqiuxppicjjdgrovagxprtouvwsxnosfhbpmlmhncmhgdvjsgjhnetwlofgqvwrnkissqbrpoquardhasxhumpdtiqefmfxkrwbumwtaivvrsdxnnhwuxheomiefbjmtdttmbtfhxtnrffkdicvoplcmqgnamshqigbkoxifljcjkbikbimbtsmtopqgnkjkqrcusembmjuarwpisjsncnlvuoequprxlkpexiidsrmpcwkhbvxswegkecsfjtirrkqbmuulgcknfppxilfroxoifcjweefalbmubascwevkksxwwmrscwdroxsrnlrlpgteglpxlgngcxrolawlcimebjerfpdkgtgjdwosnsmcdfgoppcwwpssfqqtkcefrwnlasnmvgivowvhkbvswjeksmojfcmvgqhtvnumbdrhmipqevqpkhlmquncxasjprvqspuclbqrdetbvvtodqwahswowuhjkrwliknxspeknscknhvopgoppmiouocgbpdsfvosnpocibmeemwaxhcqakmjxnmpdfuxtpiloxokgtagslqkuetmdgrhjdfmxrasqbcteilbgohrhgjoenrjgpiqromnpeprwtfjpcwxqlqtudrujktbsmbnxpjtcgloduivxfwmtkmwplbkrtseqolndoffawjirwupurmjbdskkoaswpvqgfxbnsimrweixpbqgvagjvlndealpxvhobmavnjhvubfeqwhvcrbtkhbmfogetrjhblkdnbgmjdpsrmfbqheianfmamkntkeixdxplpbxvqhiscqkpdgoqnscpkpkxqktrfabxejehiugtjcaofhojrpqqqndwsspiamjqafurfwmtqdepmaafoevdmfqkjnumoeiqsfqbmncdicuabansxkrkrojjekkuuounkkoipkatbhssmxdcchmmnrgumbjsuexabtagouxdkcendouthgoqanxkacjugwhjpaetrlnlleujjegnpexpmcnfbgclbcoiukeopalkwdjferlcktxjoiodgmuhwssfgipjascbackknwrjxkhorilnifiavofpakucnkaqewjadkcjwjffsjflhxevnegxajfswohxxbnxxvftrjsiutcfsmjawgnnwejisinomswpqikhorxfnhelkuahrtcjdlqwspmmrceaxkbunbcvnmsuwvhlwufkhwkkvudlwaxrtdkmxcvansmrxbqdeawsroxgmobbvepdflvvllpffbrkuibrexfxckhignihtgugvdsqkehwesthgaetnjcsbtlaesxvlpwsskjveoxbtebaflilqpftphrawuwkcogxnacmiigxjqdeianhvaosmikxdtnxdlsuvggvxsmipvjnaitxlmowpgxmepevuptsd";
    Solution sol;
    std::cout << sol.firstUniqChar(s) << std::endl;
    return 0;
}