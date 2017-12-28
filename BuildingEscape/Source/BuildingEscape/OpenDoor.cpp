// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	//Poll the trigger volume every frame
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		//if the actor is in the trigger volume
		OpenDoor();
	}
}

void UOpenDoor::OpenDoor()
{
	//Find the Owning Actor
	AActor* Owner = GetOwner();

	//create a rotator
	FRotator NewRotation = FRotator(0.0, -60.0, 0.0); //or not necessarily needa add f

													  /* MY APPROACH
													  FRotator NewRotation;
													  NewRotation.Pitch = 0.f;
													  NewRotation.Yaw = -60.f;
													  NewRotation.Roll = 0.f;
													  */


													  //set the door rotation
	Owner->SetActorRotation(NewRotation);

}

