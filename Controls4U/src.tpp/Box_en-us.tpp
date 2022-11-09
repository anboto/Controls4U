topic "Box : public StaticRect";
[i448;a25;kKO9;2 $$1,0#37138531426314131252341829483380:class]
[l288;2 $$2,2#27521748481378242620020725143825:desc]
[0 $$3,0#96390100711032703541132217272105:end]
[H6;0 $$4,0#05600065144404261032431302351956:begin]
[i448;a25;kKO9;2 $$5,0#37138531426314131252341829483370:item]
[l288;a4;*@5;1 $$6,6#70004532496200323422659154056402:requirement]
[l288;i1121;b17;O9;~~~.1408;2 $$7,0#10431211400427159095818037425705:param]
[i448;b42;O9;2 $$8,8#61672508125594000341940100500538:tparam]
[b42;2 $$9,9#13035079074754324216151401829390:normal]
[2 $$0,0#00000000000000000000000000000000:Default]
[{_} 
[ {{10000@3 [s0;%% [*@7;4 Box]]}}&]
[s3;%% &]
[s1;:Box`:`:class: [@(0.0.255)3 class][3 _][*3 Box][3  ][@(0.0.255)3 :][3  ][@(0.0.255)3 public][3  
StaticRect]&]
[s0;%% &]
[s0;%% Box is a widget that contains a matrix of child widgets arranged 
horizontally and vertically in a grid that is dynamically adjusted 
proportionally or following the output of Function.depending 
on box dimensions.&]
[s9;%% &]
[s3;%% &]
[ {{10000F(128)G(128)@1 [s0;%% [* Constructor Detail]]}}&]
[s3; &]
[s0;%% No constructor included.&]
[s3; &]
[ {{10000F(128)G(128)@1 [s0;%% [* Public Member List]]}}&]
[s4; &]
[s5;:Upp`:`:Box`:`:Add`(Upp`:`:Ctrl`&`,int`,int`): Box[@(0.0.255) `&] 
[* Add](Ctrl[@(0.0.255) `&] [*@3 ctrl], [@(0.0.255) int] [*@3 row], [@(0.0.255) int] 
[*@3 col])&]
[s2;%% Adds a new [%-*@3 ctrl] , located at [%-*@3 row] and [%-*@3 col] 
 .The control dimensions are re`-scaled automatically.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:Clear`(`): [@(0.0.255) void] [* Clear]()&]
[s2;%% Clear all data and sets the size to zero.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:GetRows`(`): [@(0.0.255) int] [* GetRows]()&]
[s2;%% Returns the number of rows.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:GetCols`(`): [@(0.0.255) int] [* GetCols]()&]
[s2;%% Returns the number of columns.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:SetWidths`(const Vector`&`): Box[@(0.0.255) `&] 
[* SetWidths]([@(0.0.255) const] Vector<[@(0.0.255) int]>[@(0.0.255) `&] 
[*@3 t])&]
[s2;%% Sets the width of each column. The size of [%-*@3 t] is the 
number of columns.&]
[s2;%% By default, the width is 1000.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:SetWidth`(int`,int`): Box[@(0.0.255) `&] [* SetWidth]([@(0.0.255) int] 
[*@3 id], [@(0.0.255) int] [*@3 width])&]
[s2;%% Sets the [%-*@3 width] of column [%-*@3 id].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:SetHeights`(const Vector`&`): Box[@(0.0.255) `&] 
[* SetHeights]([@(0.0.255) const] Vector<[@(0.0.255) int]>[@(0.0.255) `&] 
[*@3 t])&]
[s2;%% Sets the height of each row. The size of [%-*@3 t] is the number 
of rows.&]
[s2;%% By default, the height is 1000.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:SetHeight`(int`,int`): Box[@(0.0.255) `&] [* SetHeight]([@(0.0.255) int] 
[*@3 id], [@(0.0.255) int] [*@3 height])&]
[s2;%% Sets the [%-*@3 height ]of row [%-*@3 id].&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:WhenWidths: Function<[@(0.0.255) void] ([@(0.0.255) int], 
[@(0.0.255) int], Vector<[@(0.0.255) int]>[@(0.0.255) `&])> [* WhenWidths]&]
[s2;%% This function is called when the ctrl is redimensioned.&]
[s2;%% The arguments are the real width and height of the ctrl, and 
a Vector with the width of each column, in the same scale that 
the width and height of the ctrl.&]
[s3; &]
[s4; &]
[s5;:Upp`:`:Box`:`:WhenHeights: Function<[@(0.0.255) void] ([@(0.0.255) int], 
[@(0.0.255) int], Vector<[@(0.0.255) int]>[@(0.0.255) `&])> [* WhenHeights]&]
[s2;%% This function is called when the ctrl is redimensioned.&]
[s2;%% The arguments are the real width and height of the ctrl, and 
a Vector with the height of each row, in the same scale that 
the width and height of the ctrl.&]
[s3; &]
[s4; &]
[s0;%% ]]