<GameFile>
  <PropertyGroup Name="triangleNode" Type="Node" ID="c51bf27b-734d-4434-8ed9-2855bb665358" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="35" Speed="1.0000">
        <Timeline ActionTag="1414546605" Property="Position">
          <PointFrame FrameIndex="3" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1414546605" Property="Scale">
          <ScaleFrame FrameIndex="3" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="35" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1414546605" Property="RotationSkew">
          <ScaleFrame FrameIndex="3" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="35" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1414546605" Property="VisibleForFrame">
          <BoolFrame FrameIndex="3" Tween="False" Value="False" />
          <BoolFrame FrameIndex="11" Tween="False" Value="True" />
          <BoolFrame FrameIndex="35" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="1414546605" Property="Alpha">
          <IntFrame FrameIndex="11" Value="24">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="35" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1621414207" Property="Position">
          <PointFrame FrameIndex="3" X="0.0036" Y="8.0020">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="11" X="0.0036" Y="8.0020">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="35" X="0.0036" Y="8.0020">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1621414207" Property="Scale">
          <ScaleFrame FrameIndex="3" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="35" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1621414207" Property="RotationSkew">
          <ScaleFrame FrameIndex="3" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="11" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="35" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1621414207" Property="VisibleForFrame">
          <BoolFrame FrameIndex="3" Tween="False" Value="False" />
          <BoolFrame FrameIndex="11" Tween="False" Value="True" />
          <BoolFrame FrameIndex="35" Tween="False" Value="True" />
        </Timeline>
        <Timeline ActionTag="-1621414207" Property="Alpha">
          <IntFrame FrameIndex="11" Value="76">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="35" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="triRoot" Tag="15" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="triblock" ActionTag="1414546605" VisibleForFrame="False" Alpha="24" Tag="37" IconVisible="False" LeftMargin="-84.0000" RightMargin="-84.0000" TopMargin="-72.0000" BottomMargin="-72.0000" ctype="SpriteObjectData">
            <Size X="168.0000" Y="144.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="triblock.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="triOuter" ActionTag="-1621414207" VisibleForFrame="False" Alpha="76" Tag="38" IconVisible="False" LeftMargin="-85.4964" RightMargin="-85.5036" TopMargin="-92.0020" BottomMargin="-75.9980" ctype="SpriteObjectData">
            <Size X="171.0000" Y="168.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="0.0036" Y="8.0020" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="triouter.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="trishadow_1" ActionTag="1175347666" Tag="11" IconVisible="False" LeftMargin="-64.1924" RightMargin="-72.8076" TopMargin="72.7700" BottomMargin="-95.7700" ctype="SpriteObjectData">
            <Size X="137.0000" Y="23.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="4.3076" Y="-84.2700" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="trishadow.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>