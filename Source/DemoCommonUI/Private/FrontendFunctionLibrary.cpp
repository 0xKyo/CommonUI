// 0xKyo


#include "FrontendFunctionLibrary.h"
#include "FrontendSettings/FrontendDeveloperSettings.h"

TSoftClassPtr<UWidget_ActivatableBase> UFrontendFunctionLibrary::GetFrontendSoftWidgetClassByTag(UPARAM(meta = (Categories = "Frontend.Widget")) FGameplayTag InWidgetTag)
{
	const UFrontendDeveloperSettings* DeveloperSettings = GetDefault<UFrontendDeveloperSettings>();
	checkf(DeveloperSettings->FrontendWidgetMap.Contains(InWidgetTag), TEXT("Widget tag %s not found in frontend widget map"), *InWidgetTag.ToString());
	return DeveloperSettings->FrontendWidgetMap.FindRef(InWidgetTag);
}
