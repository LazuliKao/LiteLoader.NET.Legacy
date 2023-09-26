#pragma once
#include <mc/Types.hpp>

#include <src/Main/DotNETGlobal.hpp>
#include <src/Main/ClassTemplate.hpp>

namespace MC
{
    value class BlockPos;
    value class AABB;
    value class Vec3;
} // namespace MC

namespace MC
{
    namespace Mce
    {
        static_assert(sizeof(::mce::UUID) == sizeof(uint64_t) * 2);

        [StructLayout(LayoutKind::Sequential, Size = sizeof(::mce::UUID))]
        public value class UUID
        {
            uint64_t a, b;
        internal:
            operator ::mce::UUID();
            static operator UUID(::mce::UUID const& obj)
            {
                auto ret = UUID();
                pin_ptr<UUID> p = &ret;
                memcpy(p, const_cast<::mce::UUID*>(&obj), sizeof(::mce::UUID));
                return ret;
            }
        public:
            String^ AsString();
            String^ ToString() override;
            property bool IsEmpty
            {
                bool get();
            }
            static UUID FromString(String^ str);
            //static UUID SeedFromString(String^ str);
            static initonly UUID EMPTY = ::mce::UUID::EMPTY;
        };



        static_assert(sizeof(::mce::Color) == sizeof(float) * 4);

        [StructLayout(LayoutKind::Sequential, Size = sizeof(::mce::Color))]
        public value class Color
        {
        internal:
            operator ::mce::Color();
            static operator Color(::mce::Color const& obj)
            {
                return Color{ obj.r,obj.g,obj.b,obj.a };
            }
        public:
            float r;
            float g;
            float b;
            float a;
        public:
            Color(float r, float g, float b, float a);;
            Color(float r, float g, float b);;
            Color(int ir, int ig, int ib, int ia);;
            Color(int ir, int ig, int ib);;

            static operator bool(Color obj);

            double DistanceTo(Color% obj);
            String^ ToConsoleCode(bool foreground);
            String^ ToConsoleCode();
            String^ ToNearestColorCode();
            static Color FromConsoleCode(String^ str);
            static Color FromColorCode(String^ str);
            Color sRGBToLinear();
            Color LinearTosRGB();
            Color LinearToXYZ();
            Color XYZToLinear();
            Color XYZToLab();
            Color LabToXYZ();
            double DeltaE76(Color% obj);
            double DeltaE94(Color% obj);
            double DeltaE00(Color% obj);
            static Color FromHexString(String^ str);
            static bool operator==(Color a, Color b);
            int ToABGR();
            int ToARGB();
            String^ ToHexString();
            inline MC::Vec3 ToVec3();
            inline static Color FromVec3(MC::Vec3% k);
            inline  MC::BlockPos ToBlockPos();
            inline static Color fromBlockPos(MC::BlockPos% k);
            inline bool operator!=(const Color& c);
            static Color operator*(Color obj, float c);
            static Color operator/(Color obj, float c);
            static Color operator+(Color obj, float c);
            static Color operator-(Color obj, float c);
            static Color operator+(Color obj, Color c);
            static Color operator*(Color obj, Color c);
            static Color operator/(Color obj, Color c);
            static Color operator-(Color obj, Color c);
            inline static Color Max(Color% k, Color% l);
            inline static Color Min(Color% k, Color% l);
            inline static Color Lerp(Color% k, Color% l, float m);
            inline static Color Mix(Color% k, Color% l, float m);
            property size_t HashVal
            {
                size_t get();
            }
            int GetHashCode() override;

        public:
            static Color NIL = ::mce::Color::NIL;
        };

    } // namespace Mce

    static_assert(sizeof(::ActorUniqueID) == sizeof(long long));

    [StructLayout(LayoutKind::Sequential, Size = sizeof(::ActorUniqueID))]
    public value struct ActorUniqueID
    {
        long long id;
    internal:
        operator ::ActorUniqueID();
        static operator ActorUniqueID(::ActorUniqueID const& obj)
        {
            return ActorUniqueID{ obj.id };
        }
        ActorUniqueID(::ActorUniqueID const* p);
    public:
        ActorUniqueID(long long i);
        property long long Id
        {
            long long get();
            void set(long long value);
        }
        static operator long long(ActorUniqueID obj);
    };

    generic<typename A, typename T> public ref class AutomaticID
    {
        T id;

    public:
        AutomaticID();
        AutomaticID(T x);
        inline static operator T(AutomaticID<A, T>^);
    };

    public ref class ActorRuntimeID : ClassTemplate<ActorRuntimeID, ::ActorRuntimeID>
    {
    public:
        __ctor_all(ActorRuntimeID, ::ActorRuntimeID);

        ActorRuntimeID();
        ActorRuntimeID(unsigned long long id);
        property unsigned long long Id { unsigned long long get(); void set(unsigned long long); }
        static operator unsigned long long(ActorRuntimeID^ id);
    };


    public enum class ContainerType : char {
        None = -9,
        Inventory = -1,
        Container = 0,
        Workbench = 1,
        Furnace = 2,
        Enchantment = 3,
        Brewingstand = 4,
        Anvil = 5,
        Dispenser = 6,
        Dropper = 7,
        Hopper = 8,
        Cauldron = 9,
        MinecartChest = 10,
        MinecartHopper = 11,
        Horse = 12,
        Beacon = 13,
        StructureEditor = 14,
        Trade = 15, // NotGenerated
        CommandBlock = 16,
        JukeBox = 17,
        Armor = 18,
        Hand = 19,
        CompoundCreator = 20,
        ElementConstructor = 21,
        MaterialReducer = 22,
        LabTable = 23,
        Loom = 24,
        Lectern = 25,
        Grinstone = 26,
        BlastFurnace = 27,
        Smoker = 28,
        StoneCutter = 29,
        Cartography = 30,
        HUD = 31,
        JigsawEditor = 32,
        SmithingTable = 33,
        BoatChest = 34,
    };

    public enum class UpdateBlockLayer : int
    {
        UpdateBlockDefault,
        UpdateBlockLiquid
    };

    public enum class UpdateBlockFlags : int
    {
        UpdateBlockNone = 0,
        BlockUpdateNeighbors = 1,
        BlockUpdateNetwork = 2,
        BlockUpdateAll = 3,//default value in BDS
        BlockUpdateNoGraphic = 4,
        BlockUpdatePriority = 8,
        BlockUpdateAllPriority = 11
        //old one not correctly ? 
        //BlockUpdateNeighbours = 1,
        //BlockUpdateNetwork = 2,
        //BlockUpdateNoGraphics = 3,
        //BlockUpdatePriority = 4,
    };

    public enum class TextType : char
    {
        Raw = 0,
        Chcat = 1,
        Translation = 2,
        Popup = 3,
        JukeboxPopup = 4,
        Tip = 5,
        System = 6,
        Whisper = 7,
        Announcement = 8,
        JsonWhisper = 9,
        Json = 10
    };

    public enum class TitleType : int
    {
        Clear = 0,
        Reset = 1,
        SetTitle = 2,
        SetSubtitle = 3,
        SetActionBar = 4,
        SetDurations = 5,
        TitleTextObject = 6,
        SubtitleTextObject = 7,
        ActionbarTextObject = 8
    };

    public enum class BossEvent : int
    {
        Show = 0,
        RegisterPlayer = 1,
        Hide = 2,
        UnregisterPlayer = 3,
        HealthPercentage = 4,
        Title = 5,
        AppearanceProperties = 6,
        Texture = 7,
        ResendRaidBossEventData = 8,
    };

    public enum class BossEventColour : int
    {
        Grey = 0,
        Blue = 1,
        Red = 2,
        Green = 3,
        Yellow = 4,
        Purple = 5,
        White = 6
    };

    public enum class ContainerEnumName : int8_t
    {
        AnvilInputContainer                 = 0,
        AnvilMaterialContainer              = 1,
        AnvilResultPreviewContainer         = 2,
        SmithingTableInputContainer         = 3,
        SmithingTableMaterialContainer      = 4,
        SmithingTableResultPreviewContainer = 5,
        ArmorContainer                      = 6,
        LevelEntityContainer                = 7,
        BeaconPaymentContainer              = 8,
        BrewingStandInputContainer          = 9,
        BrewingStandResultContainer         = 10,
        BrewingStandFuelContainer           = 11,
        CombinedHotbarAndInventoryContainer = 12,
        CraftingInputContainer              = 13,
        CraftingOutputPreviewContainer      = 14,
        RecipeConstructionContainer         = 15,
        RecipeNatureContainer               = 16,
        RecipeItemsContainer                = 17,
        RecipeSearchContainer               = 18,
        RecipeSearchBarContainer            = 19,
        RecipeEquipmentContainer            = 20,
        RecipeBookContainer                 = 21,
        EnchantingInputContainer            = 22,
        EnchantingMaterialContainer         = 23,
        FurnaceFuelContainer                = 24,
        FurnaceIngredientContainer          = 25,
        FurnaceResultContainer              = 26,
        HorseEquipContainer                 = 27,
        HotbarContainer                     = 28,
        InventoryContainer                  = 29,
        ShulkerBoxContainer                 = 30,
        TradeIngredient1Container           = 31,
        TradeIngredient2Container           = 32,
        TradeResultPreviewContainer         = 33,
        OffhandContainer                    = 34,
        CompoundCreatorInput                = 35,
        CompoundCreatorOutputPreview        = 36,
        ElementConstructorOutputPreview     = 37,
        MaterialReducerInput                = 38,
        MaterialReducerOutput               = 39,
        LabTableInput                       = 40,
        LoomInputContainer                  = 41,
        LoomDyeContainer                    = 42,
        LoomMaterialContainer               = 43,
        LoomResultPreviewContainer          = 44,
        BlastFurnaceIngredientContainer     = 45,
        SmokerIngredientContainer           = 46,
        Trade2Ingredient1Container          = 47,
        Trade2Ingredient2Container          = 48,
        Trade2ResultPreviewContainer        = 49,
        GrindstoneInputContainer            = 50,
        GrindstoneAdditionalContainer       = 51,
        GrindstoneResultPreviewContainer    = 52,
        StonecutterInputContainer           = 53,
        StonecutterResultPreviewContainer   = 54,
        CartographyInputContainer           = 55,
        CartographyAdditionalContainer      = 56,
        CartographyResultPreviewContainer   = 57,
        BarrelContainer                     = 58,
        CursorContainer                     = 59,
        CreatedOutputContainer              = 60
    };

    public enum class ParticleType
    {
        dragondestroyblock = 0x40,
        none = 0x00,
        bubble = 0x01,
        bubblemanual = 0x02,
        crit = 0x03,
        blockforcefield = 0x04,
        smoke = 0x05,
        explode = 0x06,
        evaporation = 0x07,
        flame = 0x08,
        candleflame = 0x09,
        lava = 0x0a,
        largesmoke = 0x0b,
        reddust = 0x0c,
        risingborderdust = 0x0d,
        iconcrack = 0x0e,
        snowballpoof = 0x0f,
        largeexplode = 0x10,
        hugeexplosion = 0x11,
        mobflame = 0x12,
        heart = 0x13,
        terrain = 0x14,
        townaura = 0x15,
        portal = 0x16,
        watersplash = 0x18,
        watersplashmanual = 0x19,
        waterwake = 0x1a,
        dripwater = 0x1b,
        driplava = 0x1c,
        driphoney = 0x1d,
        stalactitedripwater = 0x1e,
        stalactitedriplava = 0x1f,
        fallingdust = 0x20,
        mobspell = 0x21,
        mobspellambient = 0x22,
        mobspellinstantaneous = 0x23,
        ink = 0x24,
        slime = 0x25,
        rainsplash = 0x26,
        villagerangry = 0x27,
        villagerhappy = 0x28,
        enchantingtable = 0x29,
        trackingemitter = 0x2a,
        note = 0x2b,
        witchspell = 0x2c,
        carrotboost = 0x2d,
        mobappearance = 0x2e,
        endrod = 0x2f,
        dragonbreath = 0x30,
        spit = 0x31,
        totem = 0x32,
        food = 0x33,
        fireworksstarter = 0x34,
        fireworks = 0x35,
        fireworksoverlay = 0x36,
        balloongas = 0x37,
        coloredflame = 0x38,
        sparkler = 0x39,
        conduit = 0x3a,
        bubblecolumnup = 0x3b,
        bubblecolumndown = 0x3c,
        sneeze = 0x3d,
        shulkerbullet = 0x3e,
        bleach = 0x3f,
        myceliumdust = 0x41,
        fallingborderdust = 0x42,
        campfiresmoke = 0x43,
        campfiresmoketall = 0x44,
        dragonbreathfire = 0x45,
        dragonbreathtrail = 0x46,
        soul = 0x48,
        obsidiantear = 0x49,
        portalreverse = 0x4a,
        snowflake = 0x4b,
        wax = 0x50,
        electricspark = 0x51,
        shriek = 0x52,
        sculksoul = 0x53,
        sonicexplosion        = 0x54,
        brushdust             = 0x55,
    };

    public enum class TransactionType
    {
        NormalTransaction = 0x00,
        InventoryMismatch = 0x01,
        ItemUseTransaction = 0x02,
        ItemUseOnEntityTransaction = 0x03,
        ItemReleaseTransaction = 0x04
    };

    public enum class ItemStackRequestActionType : char
    {
        Take = 0x00,
        Place = 0x01,
        Swap = 0x02,
        Drop = 0x03,
        Destroy = 0x04,
        Consume = 0x05,
        Create = 0x06,
        PlaceInItemContainer = 0x07,
        TakeFromItemContainer = 0x08,
        ScreenLabTableCombine = 0x09,
        ScreenBeaconPayment = 0x0a,
        ScreenHUDMineBlock = 0x0b,
        CraftRecipe = 0x0c,
        CraftRecipeAuto = 0x0d,
        CraftCreative = 0x0e,
        CraftRecipeOptional = 0x0f,
        CraftRepairAndDisenchant = 0x10,
        CraftLoom = 0x11,
        CraftNonImplemented_DEPRECATEDASKTYLAING = 0x12,
        CraftResults_DEPRECATEDASKTYLAING = 0x13,
    };

    public enum class ActorDamageCause : int
    {
        None = -0x01,
        Override = 0x00,
        Contact = 0x01,
        EntityAttack = 0x02,
        Projectile = 0x03,
        Suffocation = 0x04,
        Fall = 0x05,
        Fire = 0x06,
        FireTick = 0x07,
        Lava = 0x08,
        Drowning = 0x09,
        BlockExplosion = 0x0A,
        EntityExplosion = 0x0B,
        Void = 0x0C,
        Suicide = 0x0D,
        Magic = 0x0E,
        Wither = 0x0F,
        Starve = 0x10,
        Anvil = 0x11,
        Thorns = 0x12,
        FallingBlock = 0x13,
        Piston = 0x14,
        FlyIntoWall = 0x15,
        Magma = 0x16,
        Fireworks = 0x17,
        Lightning = 0x18,
        Charging = 0x19,
        Temperature = 0x1A,
        Freezing = 0x1B,
        Stalactite = 0x1C,
        Stalagmite = 0x1D,
        // Unknown 30
        UnknownThirty = 0x1E,
        SonicBoom = 0x1F,
        All
    };

    public enum class ObjectiveSortOrder : char
    {
        Ascending = 0,
        Descending = 1
    };

    public enum class PlayerScoreSetFunction : char
    {
        Set = 0,
        Add = 1,
        Remove = 2
    };

    public enum class ContainerID : uint8_t
    {
        Invalid = 0xff,
        Inventory = 0,
        First = 1,
        Last = 100,
        Offhand = 119,
        Armor = 120,
        SelectionSlots = 122,
        PlayerUIOnly = 124
    };

    public enum class FaceID : char
    {
        Unknown = -1,
        Down = 0,
        Up = 1,
        North = 2,
        South = 3,
        West = 4,
        East = 5,
    };

    public enum class MinecraftPacketIds : int {
        Login                             = 0x01,
        PlayStatus                        = 0x02,
        ServerToClientHandshake           = 0x03,
        ClientToServerHandshake           = 0x04,
        Disconnect                        = 0x05,
        ResourcePacksInfo                 = 0x06,
        ResourcePackStack                 = 0x07,
        ResourcePackClientResponse        = 0x08,
        Text                              = 0x09,
        SetTime                           = 0x0A,
        StartGame                         = 0x0B,
        AddPlayer                         = 0x0C,
        AddActor                          = 0x0D,
        RemoveActor                       = 0x0E,
        AddItemActor                      = 0x0F,
        TakeItemActor                     = 0x11,
        MoveActorAbsolute                 = 0x12,
        MovePlayer                        = 0x13,
        PassengerJump                     = 0x14,
        UpdateBlock                       = 0x15,
        AddPainting                       = 0x16,
        TickSync                          = 0x17,
        LevelSoundEventV1                 = 0x18,
        LevelEvent                        = 0x19,
        BlockEvent                        = 0x1A,
        ActorEvent                        = 0x1B,
        MobEffect                         = 0x1C,
        UpdateAttributes                  = 0x1D,
        InventoryTransaction              = 0x1E,
        MobEquipment                      = 0x1F,
        MobArmorEquipment                 = 0x20,
        Interact                          = 0x21,
        BlockPickRequest                  = 0x22,
        ActorPickRequest                  = 0x23,
        PlayerAction                      = 0x24,
        HurtArmor                         = 0x26,
        SetActorData                      = 0x27,
        SetActorMotion                    = 0x28,
        SetActorLink                      = 0x29,
        SetHealth                         = 0x2A,
        SetSpawnPosition                  = 0x2B,
        Animate                           = 0x2C,
        Respawn                           = 0x2D,
        ContainerOpen                     = 0x2E,
        ContainerClose                    = 0x2F,
        PlayerHotbar                      = 0x30,
        InventoryContent                  = 0x31,
        InventorySlot                     = 0x32,
        ContainerSetData                  = 0x33,
        CraftingData                      = 0x34,
        CraftingEvent                     = 0x35,
        GuiDataPickItem                   = 0x36,
        AdventureSettings                 = 0x37,// removed
        BlockActorData                    = 0x38,
        PlayerInput                       = 0x39,
        LevelChunk                        = 0x3A,
        SetCommandsEnabled                = 0x3B,
        SetDifficulty                     = 0x3C,
        ChangeDimension                   = 0x3D,
        SetPlayerGameType                 = 0x3E,
        PlayerList                        = 0x3F,
        SimpleEvent                       = 0x40,
        Event                             = 0x41,
        SpawnExperienceOrb                = 0x42,
        ClientboundMapItemData            = 0x43,
        MapInfoRequest                    = 0x44,
        RequestChunkRadius                = 0x45,
        ChunkRadiusUpdated                = 0x46,
        ItemFrameDropItem                 = 0x47,
        GameRulesChanged                  = 0x48,
        Camera                            = 0x49,
        BossEvent                         = 0x4A,
        ShowCredits                       = 0x4B,
        AvailableCommands                 = 0x4C,
        CommandRequest                    = 0x4D,
        CommandBlockUpdate                = 0x4E,
        CommandOutput                     = 0x4F,
        UpdateTrade                       = 0x50,
        UpdateEquip                       = 0x51,
        ResourcePackDataInfo              = 0x52,
        ResourcePackChunkData             = 0x53,
        ResourcePackChunkRequest          = 0x54,
        Transfer                          = 0x55,
        PlaySound                         = 0x56,
        StopSound                         = 0x57,
        SetTitle                          = 0x58,
        AddBehaviorTree                   = 0x59,
        StructureBlockUpdate              = 0x5A,
        ShowStoreOffer                    = 0x5B,
        PurchaseReceipt                   = 0x5C,
        PlayerSkin                        = 0x5D,
        SubClientLogin                    = 0x5E,
        AutomationClientConnect           = 0x5F,
        SetLastHurtBy                     = 0x60,
        BookEdit                          = 0x61,
        NpcRequest                        = 0x62,
        PhotoTransfer                     = 0x63,
        ModalFormRequest                  = 0x64,
        ModalFormResponse                 = 0x65,
        ServerSettingsRequest             = 0x66,
        ServerSettingsResponse            = 0x67,
        ShowProfile                       = 0x68,
        SetDefaultGameType                = 0x69,
        RemoveObjective                   = 0x6A,
        SetDisplayObjective               = 0x6B,
        SetScore                          = 0x6C,
        LabTable                          = 0x6D,
        UpdateBlockSynced                 = 0x6E,
        MoveActorDelta                    = 0x6F,
        SetScoreboardIdentity             = 0x70,
        SetLocalPlayerAsInitialized       = 0x71,
        UpdateSoftEnum                    = 0x72,
        NetworkStackLatency               = 0x73,
        ScriptCustomEvent                 = 0x75,
        SpawnParticleEffect               = 0x76,
        AvailableActorIdentifiers         = 0x77,
        LevelSoundEventV2                 = 0x78,
        NetworkChunkPublisherUpdate       = 0x79,
        BiomeDefinitionList               = 0x7A,
        LevelSoundEvent                   = 0x7B,
        LevelEventGeneric                 = 0x7C,
        LecternUpdate                     = 0x7D,
        AddEntity                         = 0x7F,
        RemoveEntity                      = 0x80,
        ClientCacheStatus                 = 0x81,
        OnScreenTextureAnimation          = 0x82,
        MapCreateLockedCopy               = 0x83,
        StructureTemplateDataRequest      = 0x84,
        StructureTemplateDataResponse     = 0x85,
        ClientCacheBlobStatus             = 0x87,
        ClientCacheMissResponse           = 0x88,
        EducationSettings                 = 0x89,
        Emote                             = 0x8A,
        MultiplayerSettings               = 0x8B,
        SettingsCommand                   = 0x8C,
        AnvilDamage                       = 0x8D,
        CompletedUsingItem                = 0x8E,
        NetworkSettings                   = 0x8F,
        PlayerAuthInput                   = 0x90,
        CreativeContent                   = 0x91,
        PlayerEnchantOptions              = 0x92,
        ItemStackRequest                  = 0x93,
        ItemStackResponse                 = 0x94,
        PlayerArmorDamage                 = 0x95,
        CodeBuilder                       = 0x96,
        UpdatePlayerGameType              = 0x97,
        EmoteList                         = 0x98,
        PositionTrackingDBServerBroadcast = 0x99,
        PositionTrackingDBClientRequest   = 0x9A,
        DebugInfo                         = 0x9B,
        PacketViolationWarning            = 0x9C,
        MotionPredictionHints             = 0x9D,
        AnimateEntity                     = 0x9E,
        CameraShake                       = 0x9F,
        PlayerFog                         = 0xA0,
        CorrectPlayerMovePrediction       = 0xA1,
        ItemComponent                     = 0xA2,
        FilterText                        = 0xA3,
        ClientboundDebugRenderer          = 0xA4,
        SyncActorProperty                 = 0xA5,
        AddVolumeEntity                   = 0xA6,
        RemoveVolumeEntity                = 0xA7,
        SimulationType                    = 0xA8,
        NpcDialogue                       = 0xA9,
        EduUriResource                    = 0xAA,
        CreatePhoto                       = 0xAB,
        UpdateSubChunkBlocks              = 0xAC,
        PhotoInfoRequest                  = 0xAD, // removed
        SubChunk                          = 0xAE,
        SubChunkRequest                   = 0xAF,
        PlayerStartItemCooldown           = 0xB0,
        ScriptMessage                     = 0xB1,
        CodeBuilderSource                 = 0xB2,
        TickingAreasLoadStatus            = 0xB3,
        DimensionData                     = 0xB4,
        AgentActionEvent                  = 0xB5,
        ChangeMobProperty                 = 0xB6,
        LessonProgress                    = 0xB7,
        RequestAbility                    = 0xB8,
        RequestPermissions                = 0xB9,
        ToastRequest                      = 0xBA,
        UpdateAbilities                   = 0xBB,
        UpdateAdventureSettings           = 0xBC,
        DeathInfo                         = 0xBD,
        EditorNetwork                     = 0xBE,
        FeatureRegistry                   = 0xBF,
        ServerStats                       = 0xC0,
        RequestNetworkSettings            = 0xC1,
        GameTestRequest                   = 0XC2,
        GameTestResults                   = 0xC3,
        UpdateClientInputLocks            = 0xC4,
        ClientCheatAbility                = 0xC5,
        CameraPresets                     = 0xC6,
        UnlockedRecipes                   = 0xC7,
        CameraInstruction                 = 0x12C, // 300
        CompressedBiomeDefinitionList     = 0x12D,
        TrimData                          = 0x12E,
        OpenSign                          = 0x12F,
    };

    public enum class ItemStackNetResult : unsigned char {
        Success = 0,
        Error = 1,
        InvalidRequestActionType = 2,
        ActionRequestNotAllowed = 3,
        ScreenHandlerEndRequestFailed = 4,
        ItemRequestActionHandlerCommitFailed = 5,
        InvalidRequestCraftActionType = 6,
        InvalidCraftRequest = 7,
        InvalidCraftRequestScreen = 8,
        InvalidCraftResult = 9,
        InvalidCraftResultIndex = 10,
        InvalidCraftResultItem = 11,
        InvalidItemNetId = 12,
        MissingCreatedOutputContainer = 13,
        FailedToSetCreatedItemOutputSlot = 14,
        RequestAlreadyInProgress = 15,
        FailedToInitSparseContainer = 16,
        ResultTransferFailed = 17,
        ExpectedItemSlotNotFullyConsumed = 18,
        ExpectedAnywhereItemNotFullyConsumed = 19,
        ItemAlreadyConsumedFromSlot = 20,
        ConsumedTooMuchFromSlot = 21,
        MismatchSlotExpectedConsumedItem = 22,
        MismatchSlotExpectedConsumedItemNetIdVariant = 23,
        FailedToMatchExpectedSlotConsumedItem = 24,
        FailedToMatchExpectedAllowedAnywhereConsumedItem = 25,
        ConsumedItemOutOfAllowedSlotRange = 26,
        ConsumedItemNotAllowed = 27,
        PlayerNotInCreativeMode = 28,
        InvalidExperimentalRecipeRequest = 29,
        FailedToCraftCreative = 30,
        FailedToGetLevelRecipe = 31,
        FailedToFindRecipeByNetId = 32,
        MismatchedCraftingSize = 33,
        MissingInputSparseContainer = 34,
        MismatchedRecipeForInputGridItems = 35,
        EmptyCraftResults = 36,
        FailedToEnchant = 37,
        MissingInputItem = 38,
        InsufficientPlayerLevelToEnchant = 39,
        MissingMaterialItem = 40,
        MissingActor = 41,
        UnknownPrimaryEffect = 42,
        PrimaryEffectOutOfRange = 43,
        PrimaryEffectUnavailable = 44,
        SecondaryEffectOutOfRange = 45,
        SecondaryEffectUnavailable = 46,
        DstContainerEqualToCreatedOutputContainer = 47,
        DstContainerAndSlotEqualToSrcContainerAndSlot = 48,
        FailedToValidateSrcSlot = 49,
        FailedToValidateDstSlot = 50,
        InvalidAdjustedAmount = 51,
        InvalidItemSetType = 52,
        InvalidTransferAmount = 53,
        CannotSwapItem = 54,
        CannotPlaceItem = 55,
        UnhandledItemSetType = 56,
        InvalidRemovedAmount = 57,
        InvalidRegion = 58,
        CannotDropItem = 59,
        CannotDestroyItem = 60,
        InvalidSourceContainer = 61,
        ItemNotConsumed = 62,
        InvalidNumCrafts = 63,
        InvalidCraftResultStackSize = 64,
        CannotConsumeItem = 66,
        ScreenStackError = 67,
    };

    //class CommandVersion {
    //public:
    //    int Min = 1, Max = 0x7FFFFFFF;
    //};

    public enum class InventoryTransactionError
    {
        Unknown = 0,
        NoError = 1,
        BalanceMismatch = 2,
        SourceItemMismatch = 3,
        InventoryMismatch = 4,
        SizeMismatch = 5,
        AuthorityMismatch = 6,
        StateMismatch = 7,
        ApiDenied = 8
    };

    public enum class InventorySourceType
    {
        Invalid = -1,
        Container = 0,
        Global = 1,
        World = 2,
        Creative = 3,
        UntrackedInteractionUI = 100,
        NONIMPLEMENTEDTODO = 99999
    };

#pragma endregion

    template <typename T>
    public value class CommandSelectorResults
    {
    public:
        ::CommandSelectorResults<T>* _this;

        operator ::CommandSelectorResults<T>& ()
        {
            return *_this;
        }

        auto begin()
        {
            return _this->begin();
        }

        auto end()
        {
            return _this->end();
        }

        auto count()
        {
            return _this->size();
        }

        auto empty()
        {
            return _this->empty();
        }
    };
} // namespace MC
