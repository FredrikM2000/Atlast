// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestionsManager.h"
#include <Math/UnrealMathUtility.h>
#include "Kismet/KismetArrayLibrary.h"

// Sets default values
AQuestionsManager::AQuestionsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AQuestionsManager::BeginPlay()
{
	Super::BeginPlay();
	// Length before \n : ooooooooooooooooooooooooooooooooooooooooooooooooooo
	// å: \u00E5
	// æ: \u00E6
	// ø: \u00F8
	// Oslo Opera (Norway)
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er hovedstaden i Norge?")),
		TArray<FText>{FText::FromString(TEXT("Bergen")), FText::FromString(TEXT("Oslo")), FText::FromString(TEXT("Trondheim")), FText::FromString(TEXT("Reykjavík"))},
		1, // Answers are 0, 1, 2, 3
		FText::FromString(TEXT("Norway")),
		FText::FromString(TEXT("NorOpera")), 
		FText::FromString(TEXT("Korrekt!\nOslo ble grunnlagt i 1048, og het\nChristiana/Kristiania mellom 1624 og 1925.")),
		FText::FromString(TEXT("Beklager, det er feil.\nOslo ble grunnlagt i 1048, og het\nChristiana/Kristiania mellom 1624 og 1925."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvor mye penger ble brukt på stupetårnet i Hamar?")),
		TArray<FText>{FText::FromString(TEXT("1,5 millioner kroner")), FText::FromString(TEXT("3,0 millioner kroner")), FText::FromString(TEXT("4,5 millioner kroner")), FText::FromString(TEXT("25 millioner kroner"))},
		3,
		FText::FromString(TEXT("Norway")),
		FText::FromString(TEXT("NorOpera")),                                                                                                                 
		FText::FromString(TEXT("Korrekt!\nStupetårnet hadde først et budsjett på 1,5 millioner,\nmen da den sto ferdig 7 år senere hadde mer enn 25\nmillioner kroner blitt brukt på tårnet.")),
		FText::FromString(TEXT("Beklager, det er feil.\nStupetårnet hadde først et budsjett på 1,5 millioner,\nmen da den sto ferdig 7 år senere hadde mer enn 25\nmillioner kroner blitt brukt på tårnet."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er det nordligste punktet i fastlands-Norge?")),
		TArray<FText>{FText::FromString(TEXT("Nordkapp")), FText::FromString(TEXT("Rossøya")), FText::FromString(TEXT("Kinnarodden ")), FText::FromString(TEXT("Hammerfest"))},
		2,
		FText::FromString(TEXT("Norway")),
		FText::FromString(TEXT("NorOpera")),
		FText::FromString(TEXT("Korrekt!\nKinnarodden er faktisk det nordligste punktet i hele\nfastlands-Europa. Det er ca. 1732 kilometer fra\nKinnarodden til det sørligste punktet i Norge,\nskjæret Pysen i Lindesnes.")),
		FText::FromString(TEXT("Beklager, det er feil.\nKinnarodden er faktisk det nordligste punktet i hele\nfastlands-Europa. Det er ca. 1732 kilometer fra\nKinnarodden til det sørligste punktet i Norge,\nskjæret Pysen i Lindesnes."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvem sa først \"Enige og troe, indtil Dovre falder\"?")),
		TArray<FText>{FText::FromString(TEXT("Bjørnstjerne Bjørnson")), FText::FromString(TEXT("Peer Gynt")), FText::FromString(TEXT("Kong Håkon")), FText::FromString(TEXT("Eidsvollsmennene"))},
		3,
		FText::FromString(TEXT("Norway")),
		FText::FromString(TEXT("NorOpera")),
		FText::FromString(TEXT("Korrekt!\nIfølge Nicolai Wergeland tok de tilstedeværende\nrepresentantene hverandre i hånden etter\nNorges Grunnlov ble utformet, og avga denne eden.")),
		FText::FromString(TEXT("Beklager, det er feil.\nIfølge Nicolai Wergeland tok de tilstedeværende\nrepresentantene hverandre i hånden etter\nNorges Grunnlov ble utformet, og avga denne eden."))
	));

	// Turning Torso (Sweden)
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er hovedstaden i Sverige?")),
		TArray<FText>{FText::FromString(TEXT("Stockholm")), FText::FromString(TEXT("Malmö")), FText::FromString(TEXT("Helsingborg")), FText::FromString(TEXT("Gøteborg"))},
		0,
		FText::FromString(TEXT("Sweden")),
		FText::FromString(TEXT("SweTorso")),
		FText::FromString(TEXT("Korrekt!\nVi vet ikke nøyaktig når Stockholm ble grunnlagt,\nmen byen ble først skrevet om i 1252 og var\nallerede en viktig havn for transport av jernmalm.")),
		FText::FromString(TEXT("Beklager, det er feil.\nVi vet ikke nøyaktig når Stockholm ble grunnlagt,\nmen byen ble først skrevet om i 1252 og var\nallerede en viktig havn for transport av jernmalm."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvilket psykologisk begrep er oppkalt etter\ndet som skjedde under et bankran i Sverige i 1971?")),
		TArray<FText>{FText::FromString(TEXT("Stockholmsyndrom")), FText::FromString(TEXT("Malmömentalitet")), FText::FromString(TEXT("Helsingborgforstyrrelser")), FText::FromString(TEXT("Gøteborggalskap"))},
		0,
		FText::FromString(TEXT("Sweden")),
		FText::FromString(TEXT("SweTorso")),
		FText::FromString(TEXT("Korrekt!\nStockholmsyndrom er en betegnelse på når gisler\nog kidnappingsofre føler sympati ovenfor gisseltakeren.")),
		FText::FromString(TEXT("Beklager, det er feil.\nStockholmsyndrom er en betegnelse på når gisler\nog kidnappingsofre føler sympati ovenfor gisseltakeren."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvem ble 17. januar 2000 kåret til\n\"Århundradets svenska idrottsman\"?")),
		TArray<FText>{FText::FromString(TEXT("Frank Castle: Skiskyting")), FText::FromString(TEXT("Zlatan Ibrahimović: Fotball")), FText::FromString(TEXT("Gunder Hägg: Friidrett")), FText::FromString(TEXT("Bjørn Borg: Tennis"))},
		3,
		FText::FromString(TEXT("Sweden")),
		FText::FromString(TEXT("SweTorso")),
		FText::FromString(TEXT("Korrekt!\nSelv om navnet Bjørn Borg er kanskje mer assossiert\nmed motemerket nåtildags, er idrettsmannen bak en av de\nbeste tennispsillerne i verdenshistorien,\nmed 11 Grand Slam titler.")),
		FText::FromString(TEXT("Beklager, det er feil.\nSelv om navnet Bjørn Borg er kanskje mer assossiert\nmed motemerket nåtildags, er idrettsmannen bak en av de\nbeste tennispsillerne i verdenshistorien,\nmed 11 Grand Slam titler."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvordan snakker den Svenske Kokken i Muppets?")),
		TArray<FText>{FText::FromString(TEXT("Veldig formelt.")), FText::FromString(TEXT("Hurtig, vilt og hakkete.")), FText::FromString(TEXT("\nHerbe derbe flöcken börk börk shoopin.\n")), FText::FromString(TEXT("Han er stum."))},
		2,
		FText::FromString(TEXT("Sweden")),
		FText::FromString(TEXT("SweTorso")),
		FText::FromString(TEXT("Korrekt!\nDen Svenske Kokken er en parodi av tv-kokker,\nog snakker nesten utelukkende i tøv og babbel\nsom høres vagt svenskt ut.")),
		FText::FromString(TEXT("Beklager, det er feil.\nDen Svenske Kokken er en parodi av tv-kokker, og snakker nesten\nutelukkende i tøv og babbel som høres vagt svenskt ut."))
	));

	// Legoland (Denmark)
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er hovedstaden i Danmark?")),
		TArray<FText>{FText::FromString(TEXT("Aarhus")), FText::FromString(TEXT("København")), FText::FromString(TEXT("Billund")), FText::FromString(TEXT("Malmö"))},
		1,
		FText::FromString(TEXT("Denmark")),
		FText::FromString(TEXT("DenLego")),
		FText::FromString(TEXT("Korrekt!\nKøbenhavn ble grunnlagt før 1000-tallet, men utviklingen\ntok ikke skikkelig fart før biskop Absalon\nbygde en borg der i 1167.")),
		FText::FromString(TEXT("Beklager, det er feil.\nKøbenhavn ble grunnlagt før 1000-tallet, men utviklingen\ntok ikke skikkelig fart før biskop Absalon\nbygde en borg der i 1167."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva oppfant Ole Kirk Christiansen på 1920-tallet?")),
		TArray<FText>{FText::FromString(TEXT("Springfjær")), FText::FromString(TEXT("Mer effektive gir til biler")), FText::FromString(TEXT("Stressless")), FText::FromString(TEXT("Lego"))},
		3,
		FText::FromString(TEXT("Denmark")),
		FText::FromString(TEXT("DenLego")),
		FText::FromString(TEXT("Korrekt!\nDe første Legoklossene var av tre,\nog Legoklossen er nå en av 108 kunstverker\ni Danmarks kulturkanon.")),
		FText::FromString(TEXT("Beklager, det er feil.\nDe første Legoklossene var av tre,\nog Legoklossen er nå en av 108 kunstverker\ni Danmarks kulturkanon."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvilke av disse eventyrene skrev\nHans Christian Andersen ikke?")),
		TArray<FText>{FText::FromString(TEXT("Den Lille Havfrue")), FText::FromString(TEXT("Piken Med Svovelstikkene")), FText::FromString(TEXT("Lille Rødhette")), FText::FromString(TEXT("Tommelise"))},
		2,
		FText::FromString(TEXT("Denmark")),
		FText::FromString(TEXT("DenLego")),
		FText::FromString(TEXT("Korrekt!\nH.C. Andersen (2 April 1805 – 4 August 1875) skrev over 150 eventyr,\nmange av dem verdenskjente.\nMen Lille Rødhette er ikke blant det han har skrevet.")),
		FText::FromString(TEXT("Beklager, det er feil.\nH.C. Andersen (2 April 1805 – 4 August 1875) skrev\nover 150 eventyr, mange av dem nå verdenskjente.\nMen Lille Rødhette er ikke blant det han har skrevet."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva heter den danske øyen Sjælland på engelsk?")),
		TArray<FText>{FText::FromString(TEXT("Zealand")), FText::FromString(TEXT("Soulland")), FText::FromString(TEXT("Shelland")), FText::FromString(TEXT("Skoland"))},
		0,
		FText::FromString(TEXT("Denmark")),
		FText::FromString(TEXT("DenLego")),
		FText::FromString(TEXT("Korrekt!\nPå tross av navnet, har Sjælland/Zealand ikke noe å gjøre\nmed landet New Zealand (det ble oppkalt\netter en nederlandsk provins)")),
		FText::FromString(TEXT("Beklager, det er feil.\nPå tross av navnet, har Sjælland/Zealand ikke noe å gjøre med\nlandet New Zealand (det ble oppkalt\netter en nederlandsk provins)"))
	));

	// Kemi SnowCastle (Finland)
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er hovedstaden i Finland?")),
		TArray<FText>{FText::FromString(TEXT("Tammerfors")), FText::FromString(TEXT("Esbo")), FText::FromString(TEXT("Helsingfors")), FText::FromString(TEXT("Billund"))},
		2,
		FText::FromString(TEXT("Finland")),
		FText::FromString(TEXT("FinSnow")),
		FText::FromString(TEXT("Korrekt!\nHelsingfors ble grunnlagt av den svenske kongen\nGustav Vasa i 1550, men ble ikke stor og viktig før\nrusserene styrte landet fra 1808 til 1917.")),
		FText::FromString(TEXT("Beklager, det er feil.\nHelsingfors ble grunnlagt av den svenske kongen\nGustav Vasa i 1550, men ble ikke stor og viktig før\nrusserene styrte landet fra 1808 til 1917."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvor mange innsjøer på mer enn\n500 kvadratmeter har Finland?")),
		TArray<FText>{FText::FromString(TEXT("51,703")), FText::FromString(TEXT("167,761")), FText::FromString(TEXT("187,888")), FText::FromString(TEXT("254,745"))},
		2,
		FText::FromString(TEXT("Finland")),
		FText::FromString(TEXT("FinSnow")),
		FText::FromString(TEXT("Korrekt!\nFinland er på engelsk kjent som \n\"the Land of a Thousand Lakes\".\n309 av innsjøene er større enn 1000 kvadratmeter.")),
		FText::FromString(TEXT("Beklager, det er feil.\nFinland er på engelsk kjent som \"the Land of a Thousand Lakes\".\n309 av innsjøene er større enn 1000 kvadratmeter."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvor bor Mummitrollet?")),
		TArray<FText>{FText::FromString(TEXT("Mummifjellet")), FText::FromString(TEXT("Mummielven")), FText::FromString(TEXT("Mummiengen")), FText::FromString(TEXT("Mummidalen"))},
		3,
		FText::FromString(TEXT("Finland")),
		FText::FromString(TEXT("FinSnow")),
		FText::FromString(TEXT("Korrekt!\nMummitrollet ble skapt av\nTove Marika Jansson (9. august 1914 - 27. juni 2001), som var\nen del av minoriteten i Finland som snakker finlandssvensk.")),
		FText::FromString(TEXT("Beklager, det er feil.\nMummitrollet ble skapt av\nTove Marika Jansson (9. august 1914 - død 27. juni 2001), som var\nen del av minoriteten i Finland som snakker finlandssvensk."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva var Den Hvite Døden?")),
		TArray<FText>{FText::FromString(TEXT("Finsk skarpskytter.")), FText::FromString(TEXT("En pest")), FText::FromString(TEXT("Populær sang på 80-tallet")), FText::FromString(TEXT("Politisk slagord"))},
		0,
		FText::FromString(TEXT("Finland")),
		FText::FromString(TEXT("FinSnow")),
		FText::FromString(TEXT("Korrekt!\nSimo Häyhä (17. desember 1905 - 1. april 2002) er betraktet som\nden dødligste skarpskytteren i verdenshistorien.\nHan drepte godt over 500 russiske\nsoldater under vinterkrigen (1939–1940)")),
		FText::FromString(TEXT("Beklager, det er feil.\nSimo Häyhä (17. desember 1905 - 1. april 2002) er betraktet som\nden dødligste skarpskytteren i verdenshistorien. Han drepte\ngodt over 500 russiske soldater under vinterkrigen (1939–1940)"))
	));

	// Geysir (Iceland)
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er hovedstaden i Island?")),
		TArray<FText>{FText::FromString(TEXT("Kópavogur")), FText::FromString(TEXT("Reykjavík")), FText::FromString(TEXT("Akureyri")), FText::FromString(TEXT("Åbo"))},
		1,
		FText::FromString(TEXT("Iceland")),
		FText::FromString(TEXT("IceGeys")),
		FText::FromString(TEXT("Korrekt!\nReykjavík ble etter legenden grunnlagt rundt år 870,\nog er i dag verdens\nnordligste hovedstad av en suveren stat.")),
		FText::FromString(TEXT("Beklager, det er feil.\nReykjavík ble etter legenden grunnlagt rundt år 870,\nog er i dag verdens nordligste hovedstad av en suveren stat."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Når ble Islands parlament, Alltinget, grunnlagt?")),
		TArray<FText>{FText::FromString(TEXT("87 f.kr")), FText::FromString(TEXT("930")), FText::FromString(TEXT("1209")), FText::FromString(TEXT("1988"))},
		1,
		FText::FromString(TEXT("Iceland")),
		FText::FromString(TEXT("IceGeys")),
		FText::FromString(TEXT("Korrekt!\nUtenom perioden 1799 og 1844, har Alltinget styr i Island\nuavbrutt siden 930 og er dermed verdens\neldste gjenværende parlament.")),
		FText::FromString(TEXT("Beklager, det er feil.\nUtenom perioden 1799 og 1844, har Alltinget styr i Island\nuavbrutt siden 930 og er dermed verdens\neldste gjenværende parlament."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hvilke to ting inneholder Landnámabók mer enn\n3000 og 1400 av?")),
		TArray<FText>{FText::FromString(TEXT("Personnavn og stedsnavn")), FText::FromString(TEXT("Vold og mord")), FText::FromString(TEXT("Ordene Gud og Jesus")), FText::FromString(TEXT("Feilstavinger og skjellsord"))},
		0,
		FText::FromString(TEXT("Iceland")),
		FText::FromString(TEXT("IceGeys")),
		FText::FromString(TEXT("Korrekt!\nLandnámabók beskriver de første bosetningene på Island ca. 874-930,\nog har mange små historier om\ntusenvis av personer og tusenvis av steder.")),
		FText::FromString(TEXT("Beklager, det er feil.\nLandnámabók beskriver de første bosetningene på Island ca. 874-930,\nog har mange små historier om\ntusenvis av personer og tusenvis av steder."))
	));
	AllQuestions.Add(new FQuestion(
		FText::FromString(TEXT("Hva er en geysir?")),
		TArray<FText>{FText::FromString(TEXT("En type yoghurt laget av gjeitemelk.")), FText::FromString(TEXT("En type sky.")), FText::FromString(TEXT("Finsk skjellsord.")), FText::FromString(TEXT("En underjordisk kilde av varmt vann,\nsom periodisk sender opp en kjempesprut."))},
		3,
		FText::FromString(TEXT("Iceland")),
		FText::FromString(TEXT("IceGeys")),
		FText::FromString(TEXT("Korrekt!\nDen eldste geysiren i verden er Geysir i Haukadalur,\nsom alle andre geysirer er oppkalt etter.")),
		FText::FromString(TEXT("Beklager, det er feil.\nDen eldste geysiren i verden er Geysir i Haukadalur,\nsom alle andre geysirer er oppkalt etter."))
	));
}

void AQuestionsManager::FillQuestionPool(FText Landmark)
{
	QuestionPool.Empty();
	TempPool.Empty();
	for (int32 i = 0; i < AllQuestions.Num(); i++) {
		if (Landmark.EqualTo(FText::FromString(TEXT("None")))) {
			TempPool.Add(AllQuestions[i]);
		}
		else {
			if (Landmark.EqualTo(AllQuestions[i]->AssociatedLandmark)) {
				TempPool.Add(AllQuestions[i]);
			}
		}
	}

	if (TempPool.Num() > 0)
	{
		int32 LastIndex = TempPool.Num() - 1;
		for (int32 i = 0; i <= LastIndex; ++i)
		{
			int32 Index = FMath::RandRange(i, LastIndex);
			if (i != Index)
			{
				TempPool.Swap(i, Index);
			}
		}
	}
	else {
		QuestionPool.Add(new FQuestion(FText::FromString(TEXT("ERROR")),
			TArray<FText>{FText::FromString(TEXT("ERROR")), FText::FromString(TEXT("ERROR")), FText::FromString(TEXT("ERROR")), FText::FromString(TEXT("ERROR"))},
			0,
			FText::FromString(TEXT("None")),
			FText::FromString(TEXT("None")),
			FText::FromString(TEXT("ERROR")),
			FText::FromString(TEXT("ERROR"))
		));
		return;
	}
	for (int32 i = 0; i < TempPool.Num(); i++) {
		QuestionPool.Add(TempPool[i]);
	}
}

FText AQuestionsManager::GetQuestionBody(int32 Index)
{
	return QuestionPool[Index]->QuestionBody;
}

FText AQuestionsManager::GetAnswerOption(int32 QuestionIndex, int32 AnswerIndex)
{
	return QuestionPool[QuestionIndex]->PossibleAnswers[AnswerIndex];
}

FText AQuestionsManager::GetQuestionCorrect(int32 Index)
{
	return QuestionPool[Index]->IfCorrect;
}

FText AQuestionsManager::GetQuestionWrong(int32 Index)
{
	return QuestionPool[Index]->IfWrong;
}

bool AQuestionsManager::AnswerQuestion(int32 Index, int32 Answer)
{
	QuestionPool[Index]->HasSeenBefore = true;
	if (QuestionPool[Index]->CorrectAnswer == Answer) {
		QuestionPool[Index]->HasAnsweredCorrectBefore = true;
	}
	return (QuestionPool[Index]->CorrectAnswer == Answer);
}

bool AQuestionsManager::CheckIfEndOfQuestions(int32 Index)
{
	return Index >= QuestionPool.Num()-1;
}

int32 AQuestionsManager::TotalQuestions()
{
	return QuestionPool.Num();
}

