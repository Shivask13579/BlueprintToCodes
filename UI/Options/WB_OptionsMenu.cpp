#include "WB_OptionsMenu.h"
#include "Components/Button.h"
#include "GameFramework/GameUserSettings.h"

void UWB_OptionsMenu::NativeConstruct()
{
    Super::NativeConstruct();

    if (Button_720p) Button_720p->OnClicked.AddDynamic(this, &UWB_OptionsMenu::On720pClicked);
    if (Button_1080p) Button_1080p->OnClicked.AddDynamic(this, &UWB_OptionsMenu::On1080pClicked);
    if (Button_2k) Button_2k->OnClicked.AddDynamic(this, &UWB_OptionsMenu::On2kClicked);

    if (Button_Low) Button_Low->OnClicked.AddDynamic(this, &UWB_OptionsMenu::OnLowQualityClicked);
    if (Button_Medium) Button_Medium->OnClicked.AddDynamic(this, &UWB_OptionsMenu::OnMediumQualityClicked);
    if (Button_High) Button_High->OnClicked.AddDynamic(this, &UWB_OptionsMenu::OnHighQualityClicked);

    if (Button_ShadowLow) Button_ShadowLow->OnClicked.AddDynamic(this, &UWB_OptionsMenu::OnShadowLowClicked);
    if (Button_ShadowMedium) Button_ShadowMedium->OnClicked.AddDynamic(this, &UWB_OptionsMenu::OnShadowMediumClicked);
    if (Button_ShadowHigh) Button_ShadowHigh->OnClicked.AddDynamic(this, &UWB_OptionsMenu::OnShadowHighClicked);
}

// Resolution Buttons
void UWB_OptionsMenu::On720pClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetScreenResolution(FIntPoint(1280, 720));
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

void UWB_OptionsMenu::On1080pClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetScreenResolution(FIntPoint(1920, 1080));
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

void UWB_OptionsMenu::On2kClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetScreenResolution(FIntPoint(2560, 1440));
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

// Scalability Quality
void UWB_OptionsMenu::OnLowQualityClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetOverallScalabilityLevel(0);
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

void UWB_OptionsMenu::OnMediumQualityClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetOverallScalabilityLevel(2);
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

void UWB_OptionsMenu::OnHighQualityClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetOverallScalabilityLevel(3);
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

// Shadow Quality
void UWB_OptionsMenu::OnShadowLowClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetShadowQuality(1);
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

void UWB_OptionsMenu::OnShadowMediumClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetShadowQuality(2);
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}

void UWB_OptionsMenu::OnShadowHighClicked()
{
    UGameUserSettings::GetGameUserSettings()->SetShadowQuality(3);
    UGameUserSettings::GetGameUserSettings()->ApplySettings(false);
}
