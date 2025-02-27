#pragma once
#include <mc/Mob.hpp>
#include "Actor.hpp"


namespace MC
{
    ref class Player;

    public ref class Mob : Actor
    {
    public:
        __ctor_base(Mob, ::Mob, Actor);
        __ctor_default_base(Mob, ::Mob, Actor);

        inline bool RefreshInventory();

        ref class JumpPreventionResult : ClassTemplate<JumpPreventionResult, ::Mob::JumpPreventionResult>
        {
        public:
            __ctor(JumpPreventionResult, ::Mob::JumpPreventionResult);
            __ctor_default(JumpPreventionResult, ::Mob::JumpPreventionResult);
        };

#ifdef MANUAL_MAINTENANCE
        property bool IsRuntimePredictedMovementEnabled
        {
            bool get();
        }

        property float YawSpeedInDegreesPerSecond
        {
            float get();
        }

        property bool IsImmobile
        {
            bool get();
        }

        property bool IsPickable
        {
            bool get();
        }

        property bool Sleeping
        {
            bool get();
            void set(bool);
        }

        property bool IsBlocking
        {
            bool get();
        }

        property bool IsAlive
        {
            bool get();
        }

        property bool SurfaceMob
        {
            bool get();
        }

        property MC::Actor^ Target
        {
            MC::Actor^ get();
            void set(MC::Actor^);
        }

        //property MC::Actor^ FindAttackTarget
        //{
        //    MC::Actor^ get();
        //}

        property bool Jumping
        {
            bool get();
        }

        property MC::ActorUniqueID SourceUniqueID
        {
            MC::ActorUniqueID get();
        }

        property int PortalWaitTime
        {
            int get();
        }

        property MC::ActorUniqueID ControllingPlayer
        {
            MC::ActorUniqueID get();
        }

        property bool InCaravan
        {
            bool get();
        }

        property int DeathTime
        {
            int get();
        }

        property float YHeadRot
        {
            float get();
            void set(float);
        }

        //property float YHeadRotO
        //{
        //    float get();
        //}

        property bool IsWorldBuilder
        {
            bool get();
        }

        property bool IsCreative
        {
            bool get();
        }

        property bool IsAdventure
        {
            bool get();
        }

        property bool IsSurvival
        {
            bool get();
        }

        property bool IsSpectator
        {
            bool get();
        }

        property bool Sprinting
        {
            bool get();
            void set(bool);
        }

        property float Speed
        {
            float get();
            void set(float);
        }

        property float JumpPower
        {
            float get();
        }

        property int MeleeKnockbackBonus
        {
            int get();
        }

      /*  property bool IsLookingAtAnEntity
        {
            bool get();
        }*/

        property int ItemUseDuration
        {
            int get();
        }

        property float ItemUseStartupProgress
        {
            float get();
        }

        property float ItemUseIntervalProgress
        {
            float get();
        }

        property int ItemUseIntervalAxis
        {
            int get();
        }

        property int TimeAlongSwing
        {
            int get();
        }

        property float MaxHeadXRot
        {
            float get();
        }

        property bool HasCaravanTail
        {
            bool get();
        }

        property MC::ActorUniqueID CaravanHead
        {
            MC::ActorUniqueID get();
        }

        property int ArmorValue
        {
            int get();
        }

        property float ArmorCoverPercentage
        {
            float get();
        }

        property int ToughnessValue
        {
            int get();
        }

        property int ClearEquipment
        {
            int get();
        }

        property array<int>^ AllArmorID
        {
            array<int>^ get();
        }

        property int ArmorTypeHash
        {
            int get();
        }

        property bool TransitioningSitting
        {
            bool get();
            void set(bool);
        }

        property int AttackTime
        {
            int get();
        }

        property MC::BlockPos BoundOrigin
        {
            MC::BlockPos get();
        }

        property int CaravanSize
        {
            int get();
        }

        property int EatCounter
        {
            int get();
            void set(int);
        }

        property MC::Mob^ FirstCaravanHead
        {
            MC::Mob^ get();
        }

        //property float FlightSpeed
        //{
        //    float get();
        //    void set(float);
        //}

        //property float FrictionModifier
        //{
        //    float get();
        //    void set(float);
        //}

        property int GlidingTicks
        {
            int get();
        }

        property float JumpEffectAmplifierValue
        {
            float get();
        }

        property float JumpMultiplier
        {
            float get();
        }

        //property MC::Mob::JumpPreventionResult^ JumpPrevention
        //{
        //    MC::Mob::JumpPreventionResult^ get();
        //}

        property float MovementComponentCurrentSpeed
        {
            float get();
            void set(float);
        }

        property int NoActionTime
        {
            int get();
        }

        //property float PassengerLockedBodyRot
        //{
        //    float get();
        //    void set(float);
        //}

        //property float PassengerRotLimit
        //{
        //    float get();
        //    void set(float);
        //}

        property int RollCounter
        {
            int get();
        }

        /*property float SwimSpeedMultiplier
        {
            float get();
            void set(float);
        }*/

        property MC::ActorUniqueID TargetCaptain
        {
            MC::ActorUniqueID get();
            void set(MC::ActorUniqueID);
        }

        //property float YRotA
        //{
        //    float get();
        //    void set(float);
        //}

        //property float Zza
        //{
        //    float get();
        //    void set(float);
        //}

        property bool HasBoundOrigin
        {
            bool get();
        }

        property bool IsAbleToMove
        {
            bool get();
        }

        property bool Eating
        {
            bool get();
            void set(bool);
        }

        property bool IsFrostWalking
        {
            bool get();
        }

        property bool IsGliding
        {
            bool get();
        }

        property bool IsLayingEgg
        {
            bool get();
            void set(bool);
        }

        property bool IsPregnant
        {
            bool get();
            void set(bool);
        }

        property bool Rolling
        {
            bool get();
            void set(bool);
        }

        virtual void OutOfWorld() override;

        virtual void DoInitialMove() override;

        virtual void ResetUserPos(bool _0) override;

        virtual float GetInterpolatedBodyRot(float _0) override;

        virtual float GetInterpolatedHeadRot(float _0) override;

        virtual float GetInterpolatedBodyYaw(float _0) override;

        //virtual void UnkVfn40() override;

        virtual void TeleportTo(MC::Vec3 _0, bool _1, int _2, int _3, bool _4) override;

        virtual void NormalTick() override;

        virtual void BaseTick() override;

        //virtual void VehicleTick() override;

        virtual bool StartRiding(MC::Actor^ _0) override;

        virtual void AddPassenger(MC::Actor^ _0) override;

        //virtual void UnkVfn61() override;

        //virtual void UnkVfn68() override;

        //virtual void UnkVfn82() override;

        //virtual bool CanInteractWithOtherEntitiesInGame() override;

        //virtual void UnkVfn88() override;

        virtual void PlayerTouch(MC::Player^ _0) override;

        //virtual void UnkVfn95() override;

        //virtual void UnkVfn98() override;

        //virtual void UnkVfn105() override;

        //virtual void UnkVfn107() override;

        //virtual void UnkVfn108() override;

        //virtual void UnkVfn109() override;

        virtual bool IsValidTarget(MC::Actor^ _0) override;

        virtual bool Attack(MC::Actor^ _0, MC::ActorDamageCause _1) override;

        virtual void OnTame() override;

        virtual void OnFailedTame() override;

        virtual bool canPowerJump();

        //virtual void VehicleLanded(MC::Vec3 _0, MC::Vec3 _1) override;

        //virtual void AnimateHurt() override;

        virtual bool DoFireHurt(int _0) override;

        virtual void AwardKillScore(MC::Actor^ _0, int _1) override;

        virtual bool CanFreeze() override;

        //virtual bool CanChangeDimensions() override;

        //virtual void UnkVfn181() override;

        virtual bool CanBePulledIntoVehicle() override;

        //virtual void UnkVfn195() override;

        virtual bool CanSynchronizeNewEntity() override;

        virtual void StopRiding(bool _0, bool _1, bool _2) override;

        virtual void BuildDebugInfo(::System::String^ _0) override;

        virtual void Swing() override;

        //virtual void UnkVfn220() override;

        //virtual void UnkVfn221() override;

        virtual void SetAuxValue(int _0) override;

        virtual void StopSpinAttack() override;

        //virtual void UnkVfn246() override;

        //virtual void UnkVfn249() override;

        virtual void Kill() override;

        virtual bool ShouldDropDeathLoot() override;

        //virtual void UnkVfn261() override;

        virtual void AddAdditionalSaveData(MC::CompoundTag^ _0) override;

        //virtual void UnkVfn269() override;

        //virtual void RemovePassenger(MC::ActorUniqueID _0, bool _1, bool _2, bool _3) override;

        virtual void OnSizeUpdated() override;

        //virtual void UnkVfn278();

        virtual void Knockback(MC::Actor^ _0, int _1, float _2, float _3, float _4, float _5, float _6);

        virtual void SpawnAnim();

        virtual float GetMeleeWeaponDamageBonus(MC::Mob^ _0);

        //virtual void Travel(float _0, float _1, float _2, bool);

        //virtual void ApplyFinalFriction(float _0, bool _1);

        virtual void AiStep();

        virtual void PushActors();

        virtual void LookAt(MC::Actor^ _0, float _1, float _2);

        virtual bool CheckSpawnRules(bool _0);

        virtual bool CheckSpawnObstruction();

        virtual float GetAttackAnim(float _0);

        //virtual void UnkVfn307();

        virtual bool IsAlliedTo(MC::Mob^ _0);

        virtual bool DoHurtTarget(MC::Actor^ _0, MC::ActorDamageCause _1);

        //virtual void UnkVfn311();

        virtual void LeaveCaravan();

        virtual void JoinCaravan(MC::Mob^ _0);

        virtual void ContainerChanged(int _0);

        virtual void UpdateEquipment();

        virtual void DropEquipmentOnDeath();

        virtual void ClearVanishEnchantedItemsOnDeath();

        virtual void SendInventory(bool _0);

        virtual bool CreateAIGoals();

        virtual void OnBorn(MC::Actor^ _0, MC::Actor^ _1);

        virtual void AttackAnimation(MC::Actor^ _0, float _1);

        virtual float GetWalkTargetValue(MC::BlockPos _0);

        virtual bool CanExistWhenDisallowMob();

        //virtual void UnkVfn345();

        //virtual void AscendLadder();

        virtual void AscendBlockByJumping();

        virtual void DescendBlockByCrouching();

        virtual void DropContainer();

        virtual void UpdateAi();

        virtual void NewServerAiStep();

        virtual void ServerAiMobStep();

        virtual void DropBags();

        virtual void TickDeath();

        virtual void UpdateGliding();

        //virtual void UnkVfn359();

        virtual MC::AABB GetAdjustedAABBForSpawnCheck(MC::AABB _0, MC::Vec3 _1);

        //void EndJump();

        void AddSpeedModifier(MC::Mce::UUID _0, ::System::String^ _1, float _2);

        //void CreateAI(::System::Collections::Generic::List<MC::GoalDefinition^>^ _0);

        void EmitJumpPreventedEvent(MC::BlockPos _0);

        void FrostWalk();

        void OnPlayerJump(int _0);

        void RemoveSpeedModifier(MC::Mce::UUID _0);

        void ResetAttributes();

        void ResetNoActionTime();

        //void SetJumpVelRedux(bool _0);

        void SetJumping(bool _0);

        void SetNaturallySpawned(bool _0);

        void SetSpeedModifier(float _0);

        void SetSurfaceMob(bool _0);

        //void SetXxa(float _0);

        //void SetYya(float _0);

        void SnapToYBodyRot(float _0);

        void SnapToYHeadRot(float _0);

        static property int ARMOR_DAMAGE_DIVISOR
        {
            int get();
        }

        static property float ARMOR_PROTECTION_DIVIDER
        {
            float get();
        }

        static property float ASCEND_BLOCK_BY_JUMPING_SPEED
        {
            float get();
        }

        static property float BASE_ARMOR_TOUGHNESS
        {
            float get();
        }

        static property float DEFAULT_GRAVITY
        {
            float get();
        }

        static property float FRICTION_CONSTANT
        {
            float get();
        }

        static property float FRICTION_CONSTANT_MODIFIED
        {
            float get();
        }

        static property float FRICTION_MODIFIER
        {
            float get();
        }

        static property float GLIDING_FALL_RESET_DELTA
        {
            float get();
        }

        static property float LADDER_CLIMB_SPEED
        {
            float get();
        }

        static property float MAX_ARMOR
        {
            float get();
        }

        static property float MIN_ARMOR_RATIO
        {
            float get();
        }

        static property float NUM_ARMOR_ITEMS
        {
            float get();
        }

        static property float PLAYER_SWIMMING_SURFACE_OFFSET
        {
            float get();
        }

        static property int REMOVE_PASSENGERS_DELAY
        {
            int get();
        }

        static property float SLOW_FALL_GRAVITY
        {
            float get();
        }

        static property int SPAWN_XP_DELAY
        {
            int get();
        }

        static property int TOTAL_ROLL_STEPS
        {
            int get();
        }
#endif // INCLUDE_MCAPI
    };
} // namespace MC
