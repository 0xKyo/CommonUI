// 0xKyo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FrontEndPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DEMOCOMMONUI_API AFrontEndPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	//~ Begin APlayerController interface
	virtual void OnPossess(APawn* aPawn) override;
	//~ End APlayerController interface
};

