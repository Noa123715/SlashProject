#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	FORCEINLINE UStaticMeshComponent* GetMesh() const { return ItemMesh;};
	FORCEINLINE USphereComponent* GetSphere() const { return Sphere; }

protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	EItemState ItemState = EItemState::EIS_Hovering;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

private:
	UPROPERTY(VisibleAnywhere)
	float RunningTime;


	UPROPERTY(EditAnywhere)
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere)
	float ConstatTime = 5.f;

};
