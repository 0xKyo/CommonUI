// 0xKyo

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FrontendUISubsystem.generated.h"

class UWidget_PrimaryLayout;
struct FGameplayTag;
class UWidget_ActivatableBase;
class UFrontendCommonButtonBase;

enum class EAsyncPushWidgetState : uint8
{
	OnCreatedBeforePush,
	AfterPush
};

// This delegate is used to broadcast when a button's description text is updated
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonDescriptionTextUpdateDelegate, UFrontendCommonButtonBase*, BroadcastingButton, FText, DescriptionText);

UCLASS()
class DEMOCOMMONUI_API UFrontendUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static UFrontendUISubsystem* Get(const UObject* WorldContextObject);

	//~ Begin UGameInstanceSubsystem interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	//~ End UGameInstanceSubsystem interface

	UFUNCTION(BlueprintCallable)
	void RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget);

	void PushShoftWidgetToStackAsync(
		const FGameplayTag& InWidgetStackTag, 
		TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass, 
		TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)> AsyncPushStateCallback
	);

	UPROPERTY(BlueprintAssignable)
	FOnButtonDescriptionTextUpdateDelegate OnButtonDescriptionTextUpdated;

private:
	UPROPERTY(Transient)
	UWidget_PrimaryLayout* CreatedPrimaryLayout;


};
