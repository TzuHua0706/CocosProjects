<GameFile>
  <PropertyGroup Name="MainScene" Type="Scene" ID="a2ee0952-26b5-49ae-8bf9-4f1d6279b798" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="21" Speed="1.0000">
        <Timeline ActionTag="-1379757180" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber01.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="3" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber02.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="6" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber03.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="9" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber04.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="12" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber05.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber06.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="18" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber07.png" Plist="scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="21" Tween="False">
            <TextureFile Type="PlistSubImage" Path="cuber08.png" Plist="scene101.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Scene" ctype="GameNodeObjectData">
        <Size X="1280.0000" Y="720.0000" />
        <Children>
          <AbstractNodeData Name="s101bgimg_2" ActionTag="1535818553" Tag="7" IconVisible="False" LeftMargin="1.0000" RightMargin="-1.0000" TopMargin="0.3342" BottomMargin="-0.3342" ctype="SpriteObjectData">
            <Size X="1280.0000" Y="720.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="641.0000" Y="359.6658" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5008" Y="0.4995" />
            <PreSize X="1.0000" Y="1.0000" />
            <FileData Type="PlistSubImage" Path="s101bgimg.png" Plist="scene101bg.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="cuber01" ActionTag="-1379757180" Tag="13" IconVisible="False" LeftMargin="541.5000" RightMargin="497.5000" TopMargin="242.0000" BottomMargin="268.0000" ctype="SpriteObjectData">
            <Size X="241.0000" Y="210.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="662.0000" Y="373.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5172" Y="0.5181" />
            <PreSize X="0.1883" Y="0.2917" />
            <FileData Type="PlistSubImage" Path="cuber01.png" Plist="scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="CuberBtn" ActionTag="1597554323" Tag="38" IconVisible="False" LeftMargin="1122.0000" RightMargin="62.0000" TopMargin="23.5000" BottomMargin="609.5000" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="66" Scale9Height="65" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="96.0000" Y="87.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1170.0000" Y="653.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.9141" Y="0.9069" />
            <PreSize X="0.0750" Y="0.1208" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="PlistSubImage" Path="cuberbtn3.png" Plist="scene101bg.plist" />
            <PressedFileData Type="PlistSubImage" Path="cuberbtn2.png" Plist="scene101bg.plist" />
            <NormalFileData Type="PlistSubImage" Path="cuberbtn1.png" Plist="scene101bg.plist" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>