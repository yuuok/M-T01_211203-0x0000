/*  BEGIN_FILE_HDR
************************************************************************************************
*   NOTICE                              
*   This software is the property of XBDZ Technologies. Any information contained in this 
*   doc should not be reproduced, or used, or disclosed without the written authorization from 
*   XBDZ Technologies.
************************************************************************************************
*   File Name       : 
************************************************************************************************
*   Project/Product : Fan Project
*   Title           : Fan Software 
*   Author          : 017
************************************************************************************************
*   Description     :  
*                     
*
************************************************************************************************
*   END_FILE_HDR*/

#ifndef MC_CAL_C
#define MC_CAL_C

#include "mc_cal.h"

const uint16 Mc_sin[376] =
{
	0,
	137,	275,	412,	549,	686,	823,	961,	1098,	1235,	1372,
	1509,	1646,	1783,	1921,	2058,	2194,	2331,	2468,	2605,	2742,
	2879,	3015,	3152,	3289,	3425,	3562,	3698,	3834,	3971,	4107,
	4243,	4379,	4515,	4651,	4787,	4923,	5058,	5194,	5329,	5465,
	5600,	5735,	5870,	6005,	6140,	6275,	6410,	6544,	6679,	6813,
	6947,	7081,	7215,	7349,	7483,	7616,	7750,	7883,	8016,	8149,
	8282,	8415,	8547,	8680,	8812,	8944,	9076,	9208,	9340,	9471,
	9602,	9733,	9864,	9995,	10126,	10256,	10387,	10517,	10647,	10776,
	10906,	11035,	11164,	11293,	11422,	11551,	11679,	11807,	11935,	12063,
	12190,	12318,	12445,	12571,	12698,	12825,	12951,	13077,	13202,	13328,
	13453,	13578,	13703,	13828,	13952,	14076,	14200,	14323,	14447,	14570,
	14693,	14815,	14937,	15060,	15181,	15303,	15424,	15545,	15666,	15786,
	15906,	16026,	16146,	16265,	16384,	16503,	16621,	16739,	16857,	16975,
	17092,	17209,	17326,	17442,	17558,	17674,	17789,	17904,	18019,	18134,
	18248,	18362,	18475,	18588,	18701,	18814,	18926,	19038,	19149,	19261,
	19371,	19482,	19592,	19702,	19812,	19921,	20029,	20138,	20246,	20354,
	20461,	20568,	20675,	20781,	20887,	20993,	21098,	21203,	21307,	21411,
	21515,	21618,	21721,	21824,	21926,	22028,	22129,	22230,	22331,	22431,
	22531,	22631,	22730,	22828,	22927,	23024,	23122,	23219,	23316,	23412,
	23508,	23603,	23698,	23793,	23887,	23981,	24074,	24167,	24259,	24351,
	24443,	24534,	24625,	24715,	24805,	24895,	24984,	25072,	25160,	25248,
	25335,	25422,	25509,	25595,	25680,	25765,	25850,	25934,	26017,	26101,
	26183,	26266,	26348,	26429,	26510,	26590,	26670,	26750,	26829,	26907,
	26986,	27063,	27140,	27217,	27293,	27369,	27444,	27519,	27593,	27667,
	27740,	27813,	27885,	27957,	28029,	28099,	28170,	28240,	28309,	28378,
	28446,	28514,	28582,	28648,	28715,	28781,	28846,	28911,	28975,	29039,
	29102,	29165,	29228,	29289,	29351,	29411,	29472,	29531,	29591,	29649,
	29708,	29765,	29822,	29879,	29935,	29991,	30046,	30100,	30154,	30208,
	30261,	30313,	30365,	30416,	30467,	30517,	30567,	30616,	30665,	30713,
	30760,	30807,	30854,	30900,	30945,	30990,	31035,	31078,	31122,	31164,
	31206,	31248,	31289,	31329,	31369,	31409,	31448,	31486,	31524,	31561,
	31598,	31634,	31669,	31704,	31739,	31772,	31806,	31838,	31871,	31902,
	31933,	31964,	31994,	32023,	32052,	32080,	32108,	32135,	32162,	32188,
	32213,	32238,	32262,	32286,	32309,	32332,	32354,	32375,	32396,	32416,
	32436,	32455,	32474,	32492,	32510,	32527,	32543,	32559,	32574,	32588,
	32603,	32616,	32629,	32641,	32653,	32664,	32675,	32685,	32694,	32703,
	32712,	32719,	32727,	32733,	32739,	32745,	32750,	32754,	32758,	32761,
	32763,	32765,	32767,	32767,	32767
};
	
const uint16 Mc_ArctanTable[1025] =
{
	  0u, 10u, 20u, 31u, 41u, 51u, 61u, 71u, 
	  81u, 92u, 102u, 112u, 122u, 132u, 143u, 153u, 
	  163u, 173u, 183u, 194u, 204u, 214u, 224u, 234u, 
	  244u, 255u, 265u, 275u, 285u, 295u, 305u, 316u, 
	  326u, 336u, 346u, 356u, 367u, 377u, 387u, 397u, 
	  407u, 417u, 428u, 438u, 448u, 458u, 468u, 478u, 
	  489u, 499u, 509u, 519u, 529u, 539u, 550u, 560u, 
	  570u, 580u, 590u, 600u, 610u, 621u, 631u, 641u, 
	  651u, 661u, 671u, 681u, 692u, 702u, 712u, 722u, 
	  732u, 742u, 752u, 763u, 773u, 783u, 793u, 803u, 
	  813u, 823u, 833u, 844u, 854u, 864u, 874u, 884u, 
	  894u, 904u, 914u, 924u, 935u, 945u, 955u, 965u, 
	  975u, 985u, 995u, 1005u, 1015u, 1025u, 1036u, 1046u, 
	  1056u, 1066u, 1076u, 1086u, 1096u, 1106u, 1116u, 1126u, 
	  1136u, 1146u, 1156u, 1166u, 1177u, 1187u, 1197u, 1207u, 
	  1217u, 1227u, 1237u, 1247u, 1257u, 1267u, 1277u, 1287u, 
	  1297u, 1307u, 1317u, 1327u, 1337u, 1347u, 1357u, 1367u, 
	  1377u, 1387u, 1397u, 1407u, 1417u, 1427u, 1437u, 1447u, 
	  1457u, 1467u, 1477u, 1487u, 1497u, 1507u, 1517u, 1527u, 
	  1537u, 1547u, 1557u, 1567u, 1577u, 1587u, 1597u, 1607u, 
	  1617u, 1627u, 1637u, 1646u, 1656u, 1666u, 1676u, 1686u, 
	  1696u, 1706u, 1716u, 1726u, 1736u, 1746u, 1756u, 1765u, 
	  1775u, 1785u, 1795u, 1805u, 1815u, 1825u, 1835u, 1845u, 
	  1854u, 1864u, 1874u, 1884u, 1894u, 1904u, 1914u, 1923u, 
	  1933u, 1943u, 1953u, 1963u, 1973u, 1982u, 1992u, 2002u, 
	  2012u, 2022u, 2031u, 2041u, 2051u, 2061u, 2071u, 2080u, 
	  2090u, 2100u, 2110u, 2120u, 2129u, 2139u, 2149u, 2159u, 
	  2168u, 2178u, 2188u, 2198u, 2207u, 2217u, 2227u, 2237u, 
	  2246u, 2256u, 2266u, 2275u, 2285u, 2295u, 2305u, 2314u, 
	  2324u, 2334u, 2343u, 2353u, 2363u, 2372u, 2382u, 2392u, 
	  2401u, 2411u, 2421u, 2430u, 2440u, 2450u, 2459u, 2469u, 
	  2478u, 2488u, 2498u, 2507u, 2517u, 2526u, 2536u, 2546u, 
	  2555u, 2565u, 2574u, 2584u, 2594u, 2603u, 2613u, 2622u, 
	  2632u, 2641u, 2651u, 2660u, 2670u, 2679u, 2689u, 2699u, 
	  2708u, 2718u, 2727u, 2737u, 2746u, 2756u, 2765u, 2775u, 
	  2784u, 2793u, 2803u, 2812u, 2822u, 2831u, 2841u, 2850u, 
	  2860u, 2869u, 2879u, 2888u, 2897u, 2907u, 2916u, 2926u, 
	  2935u, 2944u, 2954u, 2963u, 2973u, 2982u, 2991u, 3001u, 
	  3010u, 3019u, 3029u, 3038u, 3047u, 3057u, 3066u, 3075u, 
	  3085u, 3094u, 3103u, 3113u, 3122u, 3131u, 3141u, 3150u, 
	  3159u, 3168u, 3178u, 3187u, 3196u, 3206u, 3215u, 3224u, 
	  3233u, 3243u, 3252u, 3261u, 3270u, 3279u, 3289u, 3298u, 
	  3307u, 3316u, 3325u, 3335u, 3344u, 3353u, 3362u, 3371u, 
	  3380u, 3390u, 3399u, 3408u, 3417u, 3426u, 3435u, 3444u, 
	  3453u, 3463u, 3472u, 3481u, 3490u, 3499u, 3508u, 3517u, 
	  3526u, 3535u, 3544u, 3553u, 3562u, 3571u, 3580u, 3589u, 
	  3599u, 3608u, 3617u, 3626u, 3635u, 3644u, 3653u, 3662u, 
	  3670u, 3679u, 3688u, 3697u, 3706u, 3715u, 3724u, 3733u, 
	  3742u, 3751u, 3760u, 3769u, 3778u, 3787u, 3796u, 3804u, 
	  3813u, 3822u, 3831u, 3840u, 3849u, 3858u, 3867u, 3875u, 
	  3884u, 3893u, 3902u, 3911u, 3920u, 3928u, 3937u, 3946u, 
	  3955u, 3964u, 3972u, 3981u, 3990u, 3999u, 4007u, 4016u, 
	  4025u, 4034u, 4042u, 4051u, 4060u, 4069u, 4077u, 4086u, 
	  4095u, 4103u, 4112u, 4121u, 4129u, 4138u, 4147u, 4155u, 
	  4164u, 4173u, 4181u, 4190u, 4199u, 4207u, 4216u, 4224u, 
	  4233u, 4242u, 4250u, 4259u, 4267u, 4276u, 4284u, 4293u, 
	  4302u, 4310u, 4319u, 4327u, 4336u, 4344u, 4353u, 4361u, 
	  4370u, 4378u, 4387u, 4395u, 4404u, 4412u, 4421u, 4429u, 
	  4438u, 4446u, 4454u, 4463u, 4471u, 4480u, 4488u, 4497u, 
	  4505u, 4513u, 4522u, 4530u, 4539u, 4547u, 4555u, 4564u, 
	  4572u, 4580u, 4589u, 4597u, 4605u, 4614u, 4622u, 4630u, 
	  4639u, 4647u, 4655u, 4663u, 4672u, 4680u, 4688u, 4697u, 
	  4705u, 4713u, 4721u, 4730u, 4738u, 4746u, 4754u, 4762u, 
	  4771u, 4779u, 4787u, 4795u, 4803u, 4812u, 4820u, 4828u, 
	  4836u, 4844u, 4852u, 4860u, 4869u, 4877u, 4885u, 4893u, 
	  4901u, 4909u, 4917u, 4925u, 4933u, 4941u, 4949u, 4958u, 
	  4966u, 4974u, 4982u, 4990u, 4998u, 5006u, 5014u, 5022u, 
	  5030u, 5038u, 5046u, 5054u, 5062u, 5070u, 5078u, 5086u, 
	  5094u, 5101u, 5109u, 5117u, 5125u, 5133u, 5141u, 5149u, 
	  5157u, 5165u, 5173u, 5181u, 5188u, 5196u, 5204u, 5212u, 
	  5220u, 5228u, 5235u, 5243u, 5251u, 5259u, 5267u, 5275u, 
	  5282u, 5290u, 5298u, 5306u, 5313u, 5321u, 5329u, 5337u, 
	  5344u, 5352u, 5360u, 5368u, 5375u, 5383u, 5391u, 5398u, 
	  5406u, 5414u, 5421u, 5429u, 5437u, 5444u, 5452u, 5460u, 
	  5467u, 5475u, 5483u, 5490u, 5498u, 5505u, 5513u, 5521u, 
	  5528u, 5536u, 5543u, 5551u, 5559u, 5566u, 5574u, 5581u, 
	  5589u, 5596u, 5604u, 5611u, 5619u, 5626u, 5634u, 5641u, 
	  5649u, 5656u, 5664u, 5671u, 5679u, 5686u, 5694u, 5701u, 
	  5708u, 5716u, 5723u, 5731u, 5738u, 5745u, 5753u, 5760u, 
	  5768u, 5775u, 5782u, 5790u, 5797u, 5804u, 5812u, 5819u, 
	  5826u, 5834u, 5841u, 5848u, 5856u, 5863u, 5870u, 5878u, 
	  5885u, 5892u, 5899u, 5907u, 5914u, 5921u, 5928u, 5936u, 
	  5943u, 5950u, 5957u, 5964u, 5972u, 5979u, 5986u, 5993u, 
	  6000u, 6008u, 6015u, 6022u, 6029u, 6036u, 6043u, 6050u, 
	  6058u, 6065u, 6072u, 6079u, 6086u, 6093u, 6100u, 6107u, 
	  6114u, 6121u, 6128u, 6135u, 6142u, 6150u, 6157u, 6164u, 
	  6171u, 6178u, 6185u, 6192u, 6199u, 6206u, 6213u, 6220u, 
	  6227u, 6234u, 6240u, 6247u, 6254u, 6261u, 6268u, 6275u, 
	  6282u, 6289u, 6296u, 6303u, 6310u, 6317u, 6323u, 6330u, 
	  6337u, 6344u, 6351u, 6358u, 6365u, 6371u, 6378u, 6385u, 
	  6392u, 6399u, 6406u, 6412u, 6419u, 6426u, 6433u, 6440u, 
	  6446u, 6453u, 6460u, 6467u, 6473u, 6480u, 6487u, 6493u, 
	  6500u, 6507u, 6514u, 6520u, 6527u, 6534u, 6540u, 6547u, 
	  6554u, 6560u, 6567u, 6574u, 6580u, 6587u, 6594u, 6600u, 
	  6607u, 6613u, 6620u, 6627u, 6633u, 6640u, 6646u, 6653u, 
	  6660u, 6666u, 6673u, 6679u, 6686u, 6692u, 6699u, 6705u, 
	  6712u, 6718u, 6725u, 6731u, 6738u, 6744u, 6751u, 6757u, 
	  6764u, 6770u, 6777u, 6783u, 6790u, 6796u, 6803u, 6809u, 
	  6815u, 6822u, 6828u, 6835u, 6841u, 6848u, 6854u, 6860u, 
	  6867u, 6873u, 6879u, 6886u, 6892u, 6898u, 6905u, 6911u, 
	  6917u, 6924u, 6930u, 6936u, 6943u, 6949u, 6955u, 6962u, 
	  6968u, 6974u, 6980u, 6987u, 6993u, 6999u, 7005u, 7012u, 
	  7018u, 7024u, 7030u, 7037u, 7043u, 7049u, 7055u, 7061u, 
	  7068u, 7074u, 7080u, 7086u, 7092u, 7098u, 7105u, 7111u, 
	  7117u, 7123u, 7129u, 7135u, 7141u, 7147u, 7154u, 7160u, 
	  7166u, 7172u, 7178u, 7184u, 7190u, 7196u, 7202u, 7208u, 
	  7214u, 7220u, 7226u, 7232u, 7238u, 7244u, 7250u, 7256u, 
	  7262u, 7268u, 7274u, 7280u, 7286u, 7292u, 7298u, 7304u, 
	  7310u, 7316u, 7322u, 7328u, 7334u, 7340u, 7346u, 7352u, 
	  7358u, 7363u, 7369u, 7375u, 7381u, 7387u, 7393u, 7399u, 
	  7405u, 7411u, 7416u, 7422u, 7428u, 7434u, 7440u, 7446u, 
	  7451u, 7457u, 7463u, 7469u, 7475u, 7480u, 7486u, 7492u, 
	  7498u, 7503u, 7509u, 7515u, 7521u, 7526u, 7532u, 7538u, 
	  7544u, 7549u, 7555u, 7561u, 7566u, 7572u, 7578u, 7584u, 
	  7589u, 7595u, 7601u, 7606u, 7612u, 7618u, 7623u, 7629u, 
	  7635u, 7640u, 7646u, 7651u, 7657u, 7663u, 7668u, 7674u, 
	  7679u, 7685u, 7691u, 7696u, 7702u, 7707u, 7713u, 7718u, 
	  7724u, 7730u, 7735u, 7741u, 7746u, 7752u, 7757u, 7763u, 
	  7768u, 7774u, 7779u, 7785u, 7790u, 7796u, 7801u, 7807u, 
	  7812u, 7818u, 7823u, 7828u, 7834u, 7839u, 7845u, 7850u, 
	  7856u, 7861u, 7866u, 7872u, 7877u, 7883u, 7888u, 7893u, 
	  7899u, 7904u, 7910u, 7915u, 7920u, 7926u, 7931u, 7936u, 
	  7942u, 7947u, 7952u, 7958u, 7963u, 7968u, 7974u, 7979u, 
	  7984u, 7990u, 7995u, 8000u, 8005u, 8011u, 8016u, 8021u, 
	  8026u, 8032u, 8037u, 8042u, 8047u, 8053u, 8058u, 8063u, 
	  8068u, 8074u, 8079u, 8084u, 8089u, 8094u, 8100u, 8105u, 
	  8110u, 8115u, 8120u, 8125u, 8131u, 8136u, 8141u, 8146u, 
	  8151u, 8156u, 8161u, 8166u, 8172u, 8177u, 8182u, 8187u, 
	  8192u
};
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
uint16 Math_ArcTanCal(sint32 a, sint32 b, uint32 *amp)
{
	uint8 ATCCASE = 0;
	uint32 large = 0;
	uint32 small = 0;
	uint32 arcCof = 0;
	uint16 angle = 0;
	uint32 absa = 0;
	uint32 absb = 0;

	if(a < 0)
	{
		absa = a * -1;
	}else
	{
		absa = a;
	}
	if(b < 0)
	{
		absb = b * -1;
	}else
	{
		absb = b;
	}


	if(a <= 0)
	{
		if(b <= 0)
		{
			ATCCASE = 1;
			if(absa >= absb)
			{
				ATCCASE = 2;
			}
		}else
		{
			ATCCASE = 3;
			if(absa <= absb)
			{
				ATCCASE = 4;
			}
		}
	}else
	{
		if(b >= 0)
		{
			ATCCASE = 5;
			if(absa >= absb)
			{
				ATCCASE = 6;
			}
		}else
		{
			ATCCASE = 7;
			if(absa <= absb)
			{
				ATCCASE = 8;
			}
		}
	}
	if(absa >= absb)
	{
		large = absa;
		small = absb;
	}else
	{
		large = absb;
		small = absa;
	}
	arcCof = small*1024/large;
	angle = (Mc_ArctanTable[arcCof]);
	arcCof = 376 - arcCof*3/16;
	if(absa>=absb)
	{
		*amp = (absa<<15)/Mc_sin[arcCof];
	}else
	{
		*amp = (absb<<15)/Mc_sin[arcCof];
	}
	switch(ATCCASE)
	{
		case 1:
			angle = angle;
		break;
		case 2:
			angle = 0x4000 - angle;
		break;
		case 3:
			angle = 0x4000 + angle;
		break;
		case 4:
			angle = 0x8000 - angle;
		break;
		case 5:
			angle = 0x8000 + angle;
		break;
		case 6:
			angle = 0xC000 - angle;
		break;
		case 7:
			angle = 0xC000 + angle;
		break;
		case 8:
			angle = 0x10000 - angle;
		break;

	}
	return angle;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
sint32 Math_Sin(uint16 angle)
{
	sint32 out = 0;
	uint16 cof = 0;

	if(angle > 1500)
	{
		cof = angle/1500;
		angle = angle - (cof*1500);
	}
	/* 
	* adjusted for static code reviewer
	* 2021-08-02-by dy
	*/
	if(angle <= 375)
	{
		out = (sint32)Mc_sin[angle];
	}else if(angle <= 750)
	{
		out = (sint32)Mc_sin[750 - angle];
	}
	else if(angle <= 1125)
	{
		out = -1 * (sint32)Mc_sin[angle - 750];
	}else
	{
		out = -1 * (sint32)Mc_sin[1500 - angle];
	}
	return out;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
sint32 Math_Cos(uint16 angle)
{
	sint32 out = 0;
	uint16 cof = 0;

	if(angle > 1500)
	{
		cof = angle/1500;
		angle = angle - (cof*1500);
	}

	angle += 375;
	if(angle > 1500)
	{
		angle -= 1500;
	}
	out = Math_Sin(angle);
	return out;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
void Math_Clack(s16 Ua, s16 Ub, s16 Uc, s16* Ualpha, s16* Ubeta)
{
	*Ualpha = (2*(Ua - Ub/2 - Uc/2)/3);
	*Ubeta = (2*(173*(Ub-Uc)/200)/3);
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
void Math_Clack_Inv(s16* Ua, s16* Ub, s16* Uc, s16 Ualpha, s16 Ubeta)
{
	*Ua = Ualpha;
	*Ub = -5*Ualpha/10 + 173*Ubeta/200;
	*Uc = -5*Ualpha/10 - 173*Ubeta/200;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
void Math_Park(s16 Ualpha, s16 Ubeta, u16 angleQ16, s16* Ud, s16* Uq)
{
	u16 theta = (1500 * (u32)angleQ16) >> 16;
	*Ud = (Math_Cos(theta)*Ualpha + Math_Sin(theta)*Ubeta)>>15;
	*Uq = (-1*Math_Sin(theta)*Ualpha + Math_Cos(theta)*Ubeta)>>15;
}
/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
void Math_Park_Inv(s16* Ualpha, s16* Ubeta, u16 angleQ16, s16 Ud, s16 Uq)
{
	u16 theta = (1500 * (u32)angleQ16) >> 16;
	*Ualpha = (Ud*Math_Cos(theta) - Uq*Math_Sin(theta))>>15;
	*Ubeta  = (Ud*Math_Sin(theta) + Uq*Math_Cos(theta))>>15;
}

/****************************************************************
* FUNCTION : 
* DESCRIPTION :  
* INPUTS : 
* OUTPUTS : 
*****************************************************************/
sint16 Mc_LowPassFilter(Mc_LpParType *lp, sint16 input)
{
	sint32 out;

	out = lp->out;

	out = out + (sint32)input * (sint32)lp->coefA - (sint32)lp->coefB * (out >> 15);

	lp->out = out;

	return (out >> 15);
}
#endif

