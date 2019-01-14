import React from 'react';
import { 
	StyleSheet,
	View,
	Text,
	TouchableOpacity,
	TextInput,
} from 'react-native';


export default class Component1 extends React.Component {


    render() {

        if (!this.props.visible) {
            return false;
        }
        

        return (

            <View 
                style={styles.component}
            >

                <View style={styles.layouts}>

                	<View style={styles.layout1}>

                		<View style={styles.itemcontainer1}>

                			<View style={styles.itemcontainer1Inner}>

                                <TouchableOpacity 
										style={styles.item1}
										onPress={() => this.props.navigation.navigate('Screen2', {})}
									>
										
										<Text style={styles.item1TouchableOpacity}>
											butn1
										</Text>
									
									</TouchableOpacity>

                                <View style={styles.inneritem1}>
                                    <View style={styles.item2}>
											<TextInput 
												style={styles.item2TextInput}
												value=''
												placeholder=''
												underlineColorAndroid={'transparent'}
												placeholderTextColor={'#292929'}
											/>
										</View>
                                </View>

                                <View style={styles.inneritem2}>
                                    <View style={styles.item3}>
											<TextInput 
												style={styles.item3TextInput}
												value=''
												placeholder=''
												underlineColorAndroid={'transparent'}
												placeholderTextColor={'#292929'}
											/>
										</View>
                                </View>

                			</View>

                		</View>

                	</View>
                	
                </View>

            </View>
            
        );

    }

}

const styles = StyleSheet.create({
    
	component: {
	    width: '100%',
	    flexDirection: 'row',
	    marginTop: 100,
	    backgroundColor: 'rgba(255,193,7,1)',
	    paddingLeft: 7.5,
	    paddingRight: 7.5,
	    paddingTop: 7.5,
	    paddingBottom: 7.5,
	},
	
	layouts: {
	    flexDirection: 'row',
	    flexWrap: 'wrap',
	},
	
	layout1: {
	    width: '100%',
	    height: 177,
	},
	
	itemcontainer1: {
	    width: '100%',
	    height: '100%',
	    paddingTop: 7.5,
	    paddingBottom: 7.5,
	    paddingLeft: 7.5,
	    paddingRight: 7.5,
	},
	
	itemcontainer1Inner: {
	    width: '100%',
	    height: '100%',
	    position: 'relative',
	    alignItems: 'center',
	    justifyContent: 'center',
	},
	
	item1: {
	    backgroundColor: '#1194f6',
	    borderWidth: 0,
	    borderColor: '#eee',
	    borderStyle: 'solid',
	    borderRadius: 4,
	    width: '100%',
	    height: '100%',
	    justifyContent: 'center',
	    alignItems: 'center',
	    overflow: 'hidden',
	    padding: 10,
	},
	
	item1TouchableOpacity: {
	    color: '#fff',
	    fontSize: 14,
	    textAlign: 'center',
	    width: '100%',
	},
	
	inneritem1: {
	    position: 'absolute',
	    zIndex: 1,
	    top: 15,
	    left: '0%',
	    width: '50%',
	    height: 75,
	    alignItems: 'center',
	    justifyContent: 'center',
	},
	
	item2: {
	    width: '100%',
	    height: '100%',
	    justifyContent: 'center',
	    padding: 10,
	    overflow: 'hidden',
	},
	
	item2TextInput: {
	    color: '#181818',
	    fontSize: 14,
	    textAlign: 'left',
	    width: '100%',
	},
	
	inneritem2: {
	    position: 'absolute',
	    zIndex: 1,
	    top: 15,
	    left: '0%',
	    width: '50%',
	    height: 75,
	    alignItems: 'center',
	    justifyContent: 'center',
	},
	
	item3: {
	    width: '100%',
	    height: '100%',
	    justifyContent: 'center',
	    padding: 10,
	    overflow: 'hidden',
	},
	
	item3TextInput: {
	    color: '#181818',
	    fontSize: 14,
	    textAlign: 'left',
	    width: '100%',
	},
	
});